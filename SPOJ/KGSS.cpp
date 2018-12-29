//abhiy13
#include <bits/stdc++.h>
  using namespace std;

typedef long long ll;

const ll inf = 10000000000;

pair <ll , ll> min(pair <ll , ll> A , pair <ll , ll> B){
  if(A.first > B.first) return A;
  return B;
}


template <typename T , typename U>
class SegTree{
private:
  ll N = 1e5 + 7;
  ll n;
  vector < T > tree;
  T combine(T A , T B){
    U ar[4] = {A.first , A.second , B.first , B.second};
    sort(ar , ar + 4);
    return pair <ll , ll>(ar[2] , ar[3]);
  }

  T build(vector < U > ar , ll s , ll e , ll idx){
    if(s == e){
      tree[idx] = make_pair(ar[s] , 0);
      return tree[idx];
    }
    ll mid = (s+e) >> 1;
    ll lf = idx << 1;
    ll rf = lf|1;
    tree[idx] = combine(build(ar,s,mid,lf) , build(ar,mid+1,e,rf));
    return tree[idx];
  }

  T query(ll s , ll e , ll lf , ll rf , ll idx){
    if(lf <= s and e <= rf) {return tree[idx];}
    if(rf < s or e < lf) return pair <ll , ll>(0 , 0);
    ll mid = (s+e) >> 1;
    ll l = idx << 1;
    ll r =  l|1;
    if(rf <= mid){
      return query(s , mid , lf , rf , l);
    } else if(lf > mid){
      return query(mid + 1 , e , lf , rf , r);
    } else{
      return combine(query(s , mid , lf , rf , l) , query(mid + 1 , e , lf , rf , r));
    }
  }

  void update(ll s , ll e , ll i , U val , ll idx){
    if(s > i or e < i) return;
    if(s == e){
      tree[idx] = make_pair(val , 0);
      return;
    }
    ll mid = (s+e) >> 1;
    ll lf = idx << 1;
    ll rf = lf|1;
    update(s,mid,i,val,lf);
    update(mid+1,e,i,val,rf);
    tree[idx] = combine(tree[lf] , tree[rf]);
    return;
  }
  
public:
  SegTree(vector < U > ar){
    n = ar.size();
    build(ar , 0 , n - 1 , 1);
  }

  T query(ll l ,ll r){
    return query(0 , n - 1 , l , r , 1);
  }

  void update(ll i , U val){
    update(0 , n - 1 , i , val , 1);
  }
  T getVal(ll idx){
    return tree[idx];
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
#ifdef ABHI
  freopen("input.txt" , "r" , stdin);
#endif
//  cout << ((1 << 1)|1)  << endl;
  ll N;
  cin >> N;
  vector < ll > ar(N);
  for(ll &x : ar) cin >> x;
  SegTree < pair < ll , ll > , ll > tree(ar);
  ll Q;
  cin >> Q;
  while(Q--){
    char ch;
    cin >> ch;
    if(ch == 'Q'){
      ll x, y;
      cin >> x >> y;
      pair <ll ,ll> res = tree.query(x - 1 , y - 1);
      cout << res.first + res.second << '\n'; 
    } else {
      ll x , val;
      cin >> x >> val;
      tree.update(x - 1 , val);
    }
  }
#ifdef ABHI
  cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
#endif
  return 0;
}
