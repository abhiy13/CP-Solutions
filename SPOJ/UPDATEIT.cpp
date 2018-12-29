//abhiy13
#include <bits/stdc++.h>
  using namespace std;


string to_string(string s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef ABHI
  #define line_debug(x) cerr << "[" << __LINE__ << "]: " << #x << "->" << to_string(x) << '\n';
  #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
  #define line_debug(x) 42
  #define debug(...) 42
#endif


class SegTree{
public:
  int res = 0;
  struct Node{
    // don't forget to set default value (used for leaves)
    // not necessarily neutral element!
    int x = 0;
    int add = 0;
    void apply(int val){
      x = val;
    }
    void update(int val){
      x += val;
    }
  };
private:
  vector < Node > tree;
  int N , n;

  // for lazy propogation
  inline void push(int x , int l , int r){
    if(tree[x].add != 0){
      tree[x].update(tree[x].add);
      if(l != r){
        tree[x << 1].add += (tree[x].add);
        tree[(x << 1)|1].add += (tree[x].add);
      }
      tree[x].add = 0;
    }
  }

  Node combine(const Node &A , const Node &B){
    Node ans;
    ans.x = max(A.x , B.x);
    return ans;
  }
  
  void build(int s , int e , int idx) {
    if(s == e){
      tree[idx].apply(0);
      return;
    }
    int mid = (s+e) >> 1;
    build(s , mid , (idx << 1));
    build(mid + 1 , e , ((idx << 1)|1));
    return;
  }

  template <typename T>
  void build(const vector < T > &ar , int s , int e , int idx) {
    if(s == e){
      tree[idx].apply(ar[s]);
      return;
    }
    int mid = (s+e) >> 1;
    build(ar , s , mid , (idx << 1));
    build(ar , mid + 1 , e , ((idx << 1)|1));
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

  void query(int s , int e , int i , int idx) {
    push(idx , s , e);
    if(s > i or e < i) return;
    if(s == e && e == i){
      res = tree[idx].x;
      return;
    }
    int mid = (s + e) >> 1;
    query(s , mid , i , (idx << 1));
    query(mid + 1 , e , i  , (idx << 1)|1);
    tree[idx] = combine(tree[idx << 1] , tree[(idx << 1) | 1]);
    return;
  }

  template <typename M>
  void update(int s , int e , int i , M val , int idx) {
    if(s > i or e < i) return;
    if(s == e){
      tree[idx].apply(val);
      return;
    }
    int mid = (s + e) >> 1;
    update(s , mid , i , val , (idx << 1));
    update(mid + 1 , e , i , val , (idx << 1)|1);
    tree[idx] = combine(tree[idx << 1] , tree[(idx << 1) | 1]);
    return;
  }

  template <typename M>
  void update(int s , int e , int l , int r , M val , int idx) {
    push(idx , s , e);
    if(s > r or e < l or s > e) return;
    if(l <= s && e <= r){
      tree[idx].add += val;
      push(idx , s , e);
      return;
    }
    int mid = (s + e) >> 1;
    update(s , mid , l , r , val , (idx << 1));
    update(mid + 1 , e , l , r , val , (idx << 1)|1);
    tree[idx] = combine(tree[idx << 1] , tree[(idx << 1) | 1]);
    return;
  }

public:
  template<typename T>
  SegTree(const vector<T> &ar) {
    n = (int) ar.size();
    N = 4*(n) + 1;
    tree.resize(N, {});
    build(ar , 0 , n - 1 , 1);
  }

  SegTree(int _n) : n (_n){
    N = 4 * (n) + 1;
    tree.resize(N , {});
    build(0 , n - 1 , 1);
  }

  SegTree(){
    n = 100000;
    N = 4 * n + 1;
    tree.resize(N , {});
  }

  void build(){
    build(0 , n - 1 , 1); 
  }

  template<typename T>
  void build(const vector<T> &ar) {
    build(ar , 0 , n - 1 , 1);
  }

  void query(int x){
    query(0 , n - 1 , x , 1);
  }

  template<typename T>
  void update(int l , int r , T val){
    update(0 , n - 1 , l , r , val , 1);
  }

  template<typename M>
  void update(int i , M val) {
    update(0 , n - 1 , i , val , 1);
  }

  int get(int idx){
    return tree[idx].x;
  }
};


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  cin >> tt;
  while(tt--){
    int N , M;
    cin >> N >> M;
    SegTree S(N);
    for(int i = 0 ; i < M ; ++i) {
      int l , r , val;
      cin >> l >> r >> val;
      S.update(l , r , val);
    }
    vector<int> ar(N);
    for(int i = 0 ; i < N ; ++i) {
      S.query(i);
      ar[i] = S.res;
    }
    // debug(ar);
    int Q;
    cin >> Q;
    int x;
    while(Q--) {
      cin >> x;
      cout << ar[x] << '\n';
    }
  }
  return 0;
}
