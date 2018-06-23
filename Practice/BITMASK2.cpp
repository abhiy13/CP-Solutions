/******************************************
*  AUTHOR:         ABHISHEK YADAV         *
*  INSTITUITION:   CHANDIGARH UNIVERSITY  *
******************************************/
#include "bits/stdc++.h"
	using namespace std;
	
#define io std::ios::sync_with_stdio(false);cin.tie(NULL);
#define FOR(i,n) for(ll i = 0 ; i < n ; i++)
#define FORR(i,a,b) for(ll i = a ; i < b ; i++)
#define RFOR(i,a,b) for(ll i = a ; i > b ; i--)	
#define ll long long
#define llu unsigned long long
#define PB(x) push_back(x)
#define EB(x) emplace_back(x)
#define MP(a,b) make_pair(a,b)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define slld(x) scanf("%lld" , &x)
#define sid(x) scanf("%d" , &x) 
#define sllu(x) scanf("%llu" , &x)
#define plld(x) printf("%lld\n" , x)
#define pid(x) printf("%d\n" , x)
#define pllu(x) printf("%llu\n" , x)
 
 
template<typename T, typename U> inline void umin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void umax(T &x, U y) { if(x < y) x = y; }
 
 
int main(){
	#ifdef ABHI
	//	freopen("input.txt" , "r" , stdin);
	#endif
	int t;
	sid(t);
	FOR(tt,t){
		ll n;
		slld(n);
		ll ar[n] , br[n];
		FOR(i,n) slld(ar[i]);
		FOR(i,n) slld(br[i]);
		sort(ar,ar+n,greater<ll>());
		sort(br,br+n);
		ll res = 0;
		FOR(i,n) res += (ar[i]*br[i]);
		plld(res);		
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
