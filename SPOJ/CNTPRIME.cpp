//abhiy13
#include <bits/stdc++.h>

using namespace std;

const int n = 1000010;
bool prime[n + 1]; 
void sieve(){ 
  memset(prime, true, sizeof(prime)); 
  for (int p = 2 ; p * p <= n; ++p) { 
    if (prime[p] == true) {  
      for (int i = p * 2 ; i <= n ; i += p) 
          prime[i] = false; 
    } 
  }  
} 

const int MAXN = (int)(1e5 + 10);

struct Node {
  int x = 0;
  int add = -1;
};
Node tree[4 * MAXN];
int ar[MAXN];

// for lazy propogation
inline void push(int x , int l , int r){
  if(tree[x].add != -1){
    tree[x].x = (r - l + 1) * (tree[x].add);
    if(l != r){
      tree[x << 1].add = (tree[x].add);
      tree[(x << 1)|1].add = (tree[x].add);
    }
    tree[x].add = -1;
  }
}

Node combine(const Node &A , const Node &B){
  Node ans;
  ans.x = A.x + B.x;
  return ans;
}

void build(int s , int e , int idx) {
  if(s == e){
    tree[idx].x = ((int) prime[ar[s]]);
    tree[idx].add = -1;
    return;
  }
  int mid = (s+e) >> 1;
  build(s , mid , (idx << 1));
  build(mid + 1 , e , ((idx << 1)|1));
  tree[idx] = combine(tree[idx << 1] , tree[(idx << 1)|1]);
  return;
}

Node query(int s , int e , int lf , int rf , int idx) {
  push(idx , s , e);
  if(rf < s or e < lf) return Node();
  if(lf <= s and e <= rf){
   return tree[idx];
  }
  int mid = (s + e) >> 1;
  int l = idx << 1;
  int r =  (idx << 1) | 1;
  if(lf <= mid){
    if(rf <= mid){
      return query(s , mid , lf , rf , l);
    }else{
      return combine(query(s , mid , lf , rf , l) , query(mid + 1 , e , lf , rf , r));
    }
  }else{
    return query(mid + 1 , e , lf , rf , r);
  }
}

void update(int s , int e , int l , int r , int val , int idx) {
  push(idx , s , e);
  if(s > r or e < l or s > e) return;
  if(l <= s && e <= r){
    tree[idx].add = val;
    push(idx , s , e);
    return;
  }
  int mid = (s + e) >> 1;
  update(s , mid , l , r , val , (idx << 1));
  update(mid + 1 , e , l , r , val , (idx << 1)|1);
  tree[idx] = combine(tree[idx << 1] , tree[(idx << 1) | 1]);
  return;
}

int main(){
  sieve();
  int tt;
  scanf("%d", &tt);
  for(int ttt = 1; ttt <= tt; ++ttt) {
    printf("Case %d:\n", ttt);
    int N, M;
    scanf("%d %d", &N, &M);
    memset(ar, 0, sizeof ar);
    for(int i = 0; i < N; ++i) {
      scanf("%d", ar + i);
    }
    build(0, N - 1, 1);
    int t, x, y, v;
    while(M--) {
      scanf("%d %d %d", &t, &x, &y);
      --x, --y;
      if(t&1) {
        printf("%d\n", query(0, N - 1, x, y, 1).x); 
      } else {
        scanf("%d", &v);
        update(0, N - 1, x, y, prime[v], 1);
      }
    }
  }
  return 0;
}
