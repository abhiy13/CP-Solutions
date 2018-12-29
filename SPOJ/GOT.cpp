//abhiy13
#include <bits/stdc++.h>
  using namespace std;
 
const int MAXN = 123456;
int N , M;
struct Node {
  int x;
  Node* l, *r;
  Node(Node* _l = NULL , Node* _r = NULL , int _x = 0) {
    l = _l;
    r = _r;
    x = _x;
  }
};
 
Node* versions[MAXN];
int ar[MAXN];
void build(Node* tree , int l , int r) {
  if(r < l) return;
  if(l == r) {
    tree->x = 0;
    return;
  }
  int mid = (l + r) >> 1;
  tree->l = new Node();
  tree->r = new Node();
  build(tree->l , l , mid);
  build(tree->r , mid + 1 , r);
  tree->x = tree->l->x + tree->r->x;
}
 
void update(Node* old, Node* curr, int l , int r , int idx , int val) {
  if(idx < l || idx > r || r < l) return;
  if(l == r) {
   curr->x = old->x + val;
   return;
  }
  int mid = (l + r) >> 1;
  if(idx <= mid) {
   curr->r = old->r;
   curr->l = new Node();
   update(old->l , curr->l , l , mid , idx , val);
  } else {
   curr->l = old->l;
   curr->r = new Node();
   update(old->r , curr->r , mid + 1 , r , idx , val);
  }
  curr->x = curr->l->x + curr->r->x;
}
 
void updatee(Node* root , int l , int r , int idx , int val) {
  if(idx < l || idx > r || r < l) return;
  if(root == NULL) {
    assert(false);
  }
  if(l == r) {
    root->x = root->x + val;
    return;
  }
  int mid = (l + r) >> 1;
  if(idx <= mid) {
    if(root->l == NULL) root->l = new Node();
    updatee(root->l , l , mid , idx , val);
  } else {
    if(root->r == NULL) root->r = new Node();
    updatee(root->r , mid + 1 , r , idx , val);
  }
}
 
int query(Node* root , int l , int r , int lo , int hi) {
  if(lo > r || hi < l || r < l) return 0;
  if(root == NULL) {
    return 0;
  }
  if(lo <= l && r <= hi) {
    return root->x;
  }
  int mid = (l + r) >> 1;
  int a = query(root->l , l , mid , lo , hi);
  int b = query(root->r , mid + 1 , r , lo , hi);
  return a + b;
}
 
int get(Node* root , int l , int r , int idx) {
  if(root == NULL) {
    return 0;
  }
  if(l == r) {
    return root->x;
  }
  int mid = (l + r) >> 1;
  if(idx <= mid) {
    return get(root->l , l , mid , idx);
  } else {
    return get(root->r , mid + 1 , r , idx);
  }
}
 
const int LG = 19;
vector<int> g[MAXN];
int parent[LG][MAXN];
int level[MAXN];
void dfs(int k, int par = -1 , int lvl = 0) {
  parent[0][k] = par;
  level[k] = lvl;
  if(par != -1) {
    versions[k] = new Node();
    update(versions[par] , versions[k] , 0 , N , ar[k] , 1);
  }
  for(auto it : g[k]) {
    if(it == par)
      continue;
    dfs(it, k, lvl+1);
  }
}
 
void precompute() {
  for(int i = 1 ; i < LG ; i++)
    for(int j = 0 ; j < N; j++)
      if(parent[i-1][j] != -1)
        parent[i][j] = parent[i-1][parent[i-1][j]];
}
 
int LCA(int u, int v) {
  if(level[u] < level[v])
    swap(u,v);
  int diff = level[u] - level[v];
  for(int i = LG - 1 ; i >= 0 ; i--) {
    if((1<<i) & diff) {
      u = parent[i][u];
    }
  }
  if(u == v)
    return u;
  for(int i = LG - 1 ; i >= 0 ; i--) {
    if(parent[i][u] != -1 && parent[i][u] != parent[i][v]) {
      u = parent[i][u];
      v = parent[i][v];
    }
  }
  return parent[0][u];
}
 
int main(){
  int cases = 0;
  while(scanf("%d %d" , &N , &M) != EOF) {
    if(cases > 0) {
      printf("\n");
    }
    cases++;
    memset(parent , -1 , sizeof parent);
    for(int i = 0 ; i < MAXN ; ++i) {
      delete versions[i];
    }
    for(int i = 0 ; i < MAXN ; ++i) {
      g[i].clear();
    }
    for(int i = 0 ; i < N ; ++i) {
      scanf("%d" , &ar[i]);
    }
    int x , y;
    for(int i = 1 ; i < N ; ++i) {
      scanf("%d %d" , &x , &y);
      x-- , y--;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    versions[0] = new Node();
    build(versions[0] , 0 , N);
    updatee(versions[0] , 0 , N , ar[0] , 1);
    dfs(0);
    precompute();
    int c;
    while(M--){
      scanf("%d %d %d" , &x , &y , &c);
      x-- , y--;
      int L = LCA(x , y);
      if(L != 0) {
        assert(parent[0][L] >= 0);
      }
      int bal = get(versions[x] , 0 , N , c) + get(versions[y] , 0 , N , c) - 2 * get(versions[L] , 0 , N , c);
      bal += (ar[L] == c ? 1 : 0);
      printf("%s", (bal > 0 ? "Find\n" : "NotFind\n"));
    }
  }
  return 0;
}
 
// Note : Submit with C++ CLANG 14 , C++ gcc 14 causes Runtime Error for some reason
