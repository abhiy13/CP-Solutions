//abhiy13
#include <bits/stdc++.h>
  using namespace std;

typedef long long ll;


template <typename T>
class fenwick {
  public:
  vector<T> fenw;
  ll n;
 
  fenwick(ll _n) : n(_n) {
    fenw.resize(n);
  }
 
  void modify(ll x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
 
  T get(ll x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};


int main(){
  ios::sync_with_stdio(false);
#ifdef ABHI
  freopen("input.txt" , "r" , stdin);
#endif
  int T;
  cin>>T;
  while(T--){
    ll N;
    cin >> N;
    unordered_map <string , ll> mp;
    ll ct = 0;
    for(int i = 0 ; i < N ; i++){
      string x;
      cin >> x;
      mp[x] = ct++;
    }
    fenwick <ll> fenw(ct);
    ll res = 0;
    vector <string> v(N);
    for(int i = 0 ; i < N ; ++i) cin >> v[i];
    for(int i = N - 1 ; i >= 0 ; --i){
      string x = v[i];
      res += fenw.get(mp[x]);
      fenw.modify(mp[x] , 1);
    }
    cout << res << '\n';
  }
#ifdef ABHI
  cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
#endif
  return 0;
}
