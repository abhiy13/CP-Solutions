#include "bits/stdc++.h"
	using namespace std;
 
#define PB(x) push_back(x)
#define EB(x) emplace_back(x)
#define F first
#define S second
 
#define TRACE
 
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
 
typedef long long ll;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;
typedef vector <int> vi;
 
inline ll distt(pll a , pll b){
	return (abs(a.F - b.F)*abs(a.F - b.F) + abs(a.S - b.S)*abs(a.S - b.S));
}
 
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	ll n , q;
	cin>>n;
	vector <pair<ll,ll>> ar(n,{0,0});
	ll dist[n] = {0};
	for(int i = 0 ;i < n ; i++){
		cin>>ar[i].F>>ar[i].S;
		dist[i] = ar[i].F*ar[i].F + ar[i].S*ar[i].S;
	}
	cin>>q;
	ll l , r;
	ll res = 0;
	while(q--){
		cin>>l>>r;
		l--,r--;
		res = 0;
		ll o = min_element(dist+l,dist+r+1) - dist;
		ll b = max_element(dist+l,dist+r+1) - dist;
		cout<<distt(ar[o],ar[b])<<endl;
	}
 	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
