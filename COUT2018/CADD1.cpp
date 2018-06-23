/*
 *	Abhishek(abhiy13)
 *	Chandigarh University
*/
 
#include "bits/stdc++.h"
	using namespace std;
 
#define io std::ios::sync_with_stdio(false);
#define FOR(i,n) for(int i = 0 ; i < n ; i++)
#define FORR(i,a,b) for(int i = a ; i < b ; i++)
#define RFOR(i,a,b) for(int i = a ; i > b ; i--)
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
	     ll n;
	     cin>>n;
	     ll count = 0;
	    /* FORR(i,1,n+1){
	          if((n^i) == (n+i)) {count++;cout<<i<<" "<<(n^i)<<" "<<n+i<<endl;}
	     }*/
	     for(;n;n>>=1){
	          if(!(n&1)) count++;
	     }
	     cout<<1LL*(1<<count)<<endl;
	}
	#ifdef ABHI
		timer
	#endif
	return 0;
} 
