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
	ll n , k;
	cin>>n>>k;
	ll m[32] , t[31];
	FOR(i,32){
		if(n&(1<<i)) m[i] = 1;
		else m[i] = 0;
	}
	ll x , res = 0;
	FOR(i,k){
		cin>>x;
		memset(t,0,sizeof(t));
		FOR(j,32){
			if(x&(1<<j)) t[j] = 1;
			else t[j] = 0;
		}
		FOR(j,32){
			if(t[j] != m[j]) res++;
		}
	}
	cout<<res<<endl;
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
