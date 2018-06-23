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
	     ll a , sum = 1;
	     FOR(i,n){
	          a = i+1;
	          if(i==0) continue;
	          sum += a + k;
	     }
	     cout<<sum<<endl;
	}
	#ifdef ABHI
		timer
	#endif
	return 0;
} 
