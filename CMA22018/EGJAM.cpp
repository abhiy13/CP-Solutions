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
		ll n , m;
		cin>>n>>m;
		ll ar[n][m];
		ll ans = 0;
		FOR(i,n) FOR(j,m) cin>>ar[i][j];
		FOR(i,n) FOR(j,m){
			bool ok = false;
			if(ar[i][j]==1){
				ok = true;
			}
			//cout<<ar[i][j]<<" "<<i<<" "<<j<<" \n";
			if(j-1>=0){
				if(ar[i][j-1]==1) ok = true;
			}
			if(j+1<m){
				if(ar[i][j+1]==1) ok = true;
			}
			if(i-1>=0){
				if(ar[i-1][j]==1) ok = true;
			}
			if(i-1>=0 and j-1 >= 0){
				if(ar[i-1][j-1]==1) ok = true;
			}
			if(i-1 >= 0 and j+1 < m){
				if(ar[i-1][j+1]==1) ok = true;
			}
			if(i+1 < n and j-1 >= 0){
				if(ar[i+1][j-1]==1) ok = true;
			}
			if(i+1 < n){
				if(ar[i+1][j]==1) ok = true;
			}
			if(i+1 < n and j+1 <m){
				if(ar[i+1][j+1]==1) ok = true;
			}
			if(ok) ans++;
		}		
		cout<<ans<<endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
