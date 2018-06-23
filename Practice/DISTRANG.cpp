#include "bits/stdc++.h"
	using namespace std;
 
 
#define PB(x) push_back(x)
#define EB(x) emplace_back(x)
#define F first
#define S second
#define FOR(i,n) for(ll i = 0 ; i < n ; i++)
#define FORR(i,a,b) for(ll i = (ll)a ; i < (ll)b ; i++)
#define RFOR(i,a,b) for(ll i = (ll)a ; i > (ll)b ; i--)
#define ll long long
#define llu unsigned long long
#define pii pair <int,int>
#define pll pair <ll,ll> 
 
 
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
	ll n;
	cin>>n;
	vector<ll> ar(n);
	for(int i = 0 ; i < n ; i++){
		cin>>ar[i];
	}
	ll q;
	cin>>q;
	vector <ll> fr(q) , to(q) , res(q);
	vector < vector <ll> > at(n , vector<ll>());
	for(int i = 0 ; i < q ; i++){
		cin>>fr[i]>>to[i];
		fr[i]-- , to[i]--;
		at[to[i]].push_back(i);
	} 
	map <ll , ll> mp;
	fenwick <ll> fenw(n);
	for(int i = 0 ; i < n ; i++){
		if(mp.find(ar[i]) != mp.end()){
			fenw.modify(mp[ar[i]] , -1);
		}
		mp[ar[i]] = i;
		fenw.modify(i,1);
		for(auto j : at[i]){
			res[j] = fenw.get(to[j]) - fenw.get(fr[j] - 1);
		}
	}	
	for(int i = 0 ; i < q ; i++){
		cout<<res[i]<<'\n';
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
}
 
