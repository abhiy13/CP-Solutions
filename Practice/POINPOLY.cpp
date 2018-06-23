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
#define debug(x) cout<<x<<" ";
#define inf 1000000000000
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
 
template<typename T, typename U> inline void umin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void umax(T &x, U y) { if(x < y) x = y; }
 
 
 
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
		ll x[n] , y[n];
		FOR(i,n) cin>>x[i]>>y[i];
		set <pll> res;
		ll req = floor(n/10);
		bool ok = false;
		FOR(i , n){ 
			FORR(j,i+2,n){
				if(i==0 and j==n-1) continue;
				if((x[i]+x[j])%2==0 and (y[i]+y[j])%2==0){
					res.insert({(x[i]+x[j])/2,(y[i]+y[j])/2});
				}
				if(res.size()==req){
					ok = true;
					break;
				}	
			}	
			if(ok) break;	
		}
		if(ok){
			for(auto p : res){
				cout<<p.F<<" "<<p.S<<endl;
			}
		}
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
