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
		freopen("input.txt" , "r" , stdin);
	#endif
	int t;
	cin>>t;
	FOR(tt,t){
		ll n;
		cin>>n;
		ll ar[n];
		ll sum = 0;
		FOR(i,n){
			cin>>ar[i];
			sum += ar[i];
		}
		ll x = 0;
		cin>>x;
		//ll bit[32];
		ll kk =0;
		//memset(bit,0,sizeof(bit));
		FOR(i,32){
			if(x&(1<<i)) kk++;
		}
		ll k = floor((double)sum/n);
		if(((k^x)>=k) or kk%2==0){
			cout<<"yes\n";
		}else{
			cout<<"no\n";
		}
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
