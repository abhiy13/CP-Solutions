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
#define pll pair <long long, long long> 
#define vi vector <int>
#define vll vector <ll>
 
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int T;
	cin>>T;
	while(T--){
		ll n , k;
		cin>>n>>k;
		vll a , b;
		ll x , p1 = 0 , p2 = 0;
		FOR(i,n){
			cin>>x;
			if(i&1) {
				b.PB(x);
				p2 += x;
			}else{
				a.PB(x);
				p1 += x;  
			}
		}	
		if(p2 > p1){
			cout<<"YES\n";
			continue;
		}
		sort(a.begin(), a.end() , greater<ll>());
		sort(b.begin(), b.end());
		bool ok = false;
		k = min(k,(ll)b.size());
		FOR(i,k){
			ll margin = a[i] - b[i];
			p2 += margin;
			p1 -= margin;
		}	
	  if(p2 > p1) ok = true;
		if(ok) cout<<"YES\n";
		else cout<<"NO\n";
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
}
 
