//abhiy13
#include <bits/stdc++.h>
  using namespace std;

#define int long long
struct Node{
  int max_sum , prefix , suffix , sum;
  Node (int sz = 0 , int pr = 0 , int sf = 0 , int sm = 0){
    max_sum = sz;
    prefix = pr;
    suffix = sf;
    sum = sm;
  }
  void apply(int x){
    max_sum = x;
    prefix = x;
    suffix = x;
    sum = x;
  }
};

template <typename T , typename U>
class SegTree{
private:
  vector < T > tree;
  long long N , n;

  T combine(T A , T B){
    Node ans;
    ans.sum = A.sum + B.sum;
    ans.max_sum = max(A.max_sum, max(B.max_sum , (A.suffix + B.prefix)));
    ans.prefix = max(A.sum + B.prefix , A.prefix);
    ans.suffix = max(B.suffix , B.sum + A.suffix);
    return ans;
  }

  void build(const vector < U > &ar , long long s , long long e , long long idx){
    if(s == e){
      tree[idx].apply(ar[s]);
      return;
    }
    long long mid = (s+e) >> 1;
    build(ar , s , mid , (idx << 1));
    build(ar , mid + 1 , e , ((idx << 1)|1));
    tree[idx] = combine(tree[idx << 1] , tree[(idx << 1)|1]);
    return;
  }

  T query(long long s , long long e , long long lf , long long rf , long long idx){
    if(rf < s or e < lf or rf < lf) return Node();//Node(numeric_limits<U>::min() , numeric_limits<U>::min() , numeric_limits<U>::min() , numeric_limits<U>::min());
    if(lf <= s and e <= rf) return tree[idx];
    long long mid = (s+e) >> 1;
    long long l = idx << 1;
    long long r =  (idx << 1) | 1;
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

  void update(long long s , long long e , long long i , U val , long long idx){
    if(s > i or e < i) return;
    if(s == e){
      tree[idx].apply(val);
      return;
    }
    long long mid = (s+e) >> 1;
    update(s , mid , i , val , (idx << 1));
    update(mid + 1 , e , i , val , (idx << 1)|1);
    tree[idx] = combine(tree[idx << 1] , tree[(idx << 1) | 1]);
    return;
  }
public:
  SegTree(const vector < U > &ar){
    n = min((int) ar.size() , (int) 50007);
    N = ((50007) << 3);
    tree.resize(N, {});
    build(ar , 0 , n - 1 , 1);
  }

  SegTree(){
    n = 100000;
    N = 4 * n + 1;
    tree.resize(N , {});
  }

  void build(const vector <U> &ar){
    build(ar , 0 , n - 1 , 1);
  }

  T query(long long l ,long long r){
    return query(0 , n - 1 , l , r , 1);
  }

  void update(int i , U val){
    update(0 , n - 1 , i , val , 1);
  }
};
#undef int

int main(){
#define int long long
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> ar(N , 0);
  for(auto &x : ar) cin >> x;
  SegTree <Node , int> S(ar);
  int Q;
  cin >> Q;
  while(Q--){
    int x , l , r;
    cin >> x >> l >> r;
    l-- , r--;
    if(x == 0){
      r++;
      S.update(l , r);
    } else {
      int ans = (S.query(l , r).max_sum);
      cout << ans << '\n';
    }
  }
  return 0;
}
