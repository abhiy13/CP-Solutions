/*
 *	Abhishek(abhiy13)
 *	Chandigarh University
*/
 
#include "bits/stdc++.h"
	using namespace std;
 
#define io std::ios::sync_with_stdio(false);
#define FOR(i,n) for(int i = 0 ; i < n ; i++)
#define rep(i,a,b) for(int i = a ; i < b ; i++)
#define rrep(i,a,b) for(int i = a ; i > b ; i--)
#define timer cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
#define all(x) begin(x),end(x)
 
typedef long long ll;
typedef unsigned long long llu;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const int mod = 1e9+7;
 
ll cal(ll arp[] ,ll arw[] ,ll n ,ll k){
     ll ans[n+1][k+1];
     FOR(i,n+1) FOR(j,k+1){
          if(i==0 || j==0) ans[i][j] = 0;
          else if(arw[i-1] <= j){
               ans[i][j] = max(arp[i-1]+ans[i-1][j-arw[i-1]] , ans[i-1][j]);
          }else{
               ans[i][j] = ans[i-1][j];
          }
     }
     return ans[n][k];
}
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int t;
	cin>>t;
	while(t--){
	     ll n , k;
	     cin>>n>>k;
	     ll arp[n] , arw[n];
	     FOR(i,n) cin>>arp[i];
	     FOR(i,n) cin>>arw[i];
	     cout<<cal(arp,arw,n,k)<<endl;
	}
	#ifdef ABHI
		timer
	#endif
	return 0;
} 
