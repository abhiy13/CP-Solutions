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
#define MOD 1000000007
 
ll modpow(ll n ,ll p){
	ll ans = 1;
	n %= MOD;
	for(;p;p>>=1){
		if(p&1){
			ans = (ans*n)%MOD;
		}
		n = (n*n)%MOD;
	}
	return ans;
}
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	ll dp[100006];
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	FORR(i,1,100005){
		dp[i] = dp[i-1] + 3*dp[i-1];
		dp[i] %= MOD;
	}
	int t;
	cin>>t;
	FOR(tt,t){
		ll n , r;
		cin>>n>>r;
		n%=MOD;
		ll res = (n*dp[r-1])%MOD;
		cout<<res<<endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
