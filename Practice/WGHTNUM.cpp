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
 
ll ans(ll n){
	ll res = 0;
	string s = to_string(n);
	//cout<<s<<" ";
	FORR(i,1,(ll)s.size()){
		res += (s[i]-'0') - (s[i-1]-'0');
	}
	return res;
}
 
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
	int t;
	cin>>t;
	FOR(tt,t){
		ll n , k;
		cin>>n>>k;
		ll res = 0;
		//cout<<p<<" "<<kk<<endl;
		FORR(i,10,100){
			if(ans(i)==k) res++;
		}
		res = (res%MOD * modpow(10,n-2))%MOD;
		cout<<res<<endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
}  
