#include "bits/stdc++.h"
	using namespace std;
 
#define io std::ios::sync_with_stdio(false);
#define FOR(i,n) for(ll i = 0 ; i < n ; i++)
#define FORR(i,a,b) for(ll i = a ; i < b ; i++)
#define RFOR(i,a,b) for(ll i = a ; i > b ; i--)	
#define ll long long
#define llu unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second  
#define slld(x) scanf("%lld" , &x)
#define sii(x) scanf("%d" , &x)
#define sdoub(x) scanf("%lf" , &x)
 
 
int main(){
	io
	#ifdef ABHI
	//	freopen("input.txt" , "r" , stdin);
	#endif
	ll a = 0 , b = 0 , c;
	FOR(i,7){
		cin>>c;
		a += c;
	}
	FOR(i,7){
		cin>>c;
		b += c;
	}
	//cout<<a<<" "<<b<<endl;
	cout<<((a==b)?"draw":(a>b)?"cse":"mech")<<endl;
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
