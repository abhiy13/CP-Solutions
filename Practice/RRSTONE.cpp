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
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	ll n , k;
	cin>>n>>k;
	ll ar[n] , mx = -190000000 , mn = 100000000;
	FOR(i,n){
		cin>>ar[i];
		mx = max(ar[i] , mx);
		mn = min(ar[i] , mn);
	}
	if(k==0){
		FOR(i,n) cout<<ar[i]<<" ";
		cout<<endl;
	}else{
		FOR(i,n) ar[i] = mx - ar[i];
		if(k&1){
			FOR(i,n) cout<<ar[i]<<" ";
		}else{
			FOR(i,n) ar[i] = (mx-mn) - ar[i];
			FOR(i,n) cout<<ar[i]<<" "; 
		}
		cout<<endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
}
 
