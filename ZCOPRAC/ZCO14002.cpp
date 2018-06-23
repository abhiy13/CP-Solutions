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
#define pll pair <int,int> 
#define vi vector <int>
 
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	ll n;
	cin>>n;
	ll ar[n];
	FOR(i,n) cin>>ar[i];
	ll dp[n];
	memset(dp,1000000,sizeof dp);
	for(int i = 0 ; i < n ; i++){
		for(int j = 1 ; j <= 3 ; j++){
			if(i - j >= 0)
				dp[i] = min(dp[i] , ar[i] + dp[i - j]);
			else 
				dp[i] = ar[i];
		}
	}
	//FOR(i,n) cout<<dp[i]<<" ";
	ll res = min(dp[n-1] , min(dp[n-2] , dp[n-3]));
	cout<<res<<endl;
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
}
 
