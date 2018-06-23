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
 
 
/*

	ll ind = upper_bound(ar,ar+n,ar[i]+ar[i-1]) - ar;
			if(ind == n) res += 0;
			else res += n-ind; 
		

*/
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	ll n;
	while(1){
		cin>>n;
		if(n==0) break;
		ll ar[n] , res = 0;
		FOR(i,n) cin>>ar[i];
		sort(ar,ar+n);
		for(ll i = n-1 ; i >= 2 ; i--){
			ll k = i-1;
			ll p = 0;
			while(k >= p){
				if(ar[k] + ar[p] < ar[i]){
					res += k-p ;
				//	cout<<ar[k]<<" "<<ar[p]<<" "<<ar[i]<<endl;
					p++;
				}else{
					k--;
				}
			}
		}
		cout<<res<<endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
