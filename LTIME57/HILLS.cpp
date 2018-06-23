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
	     ll n , u , d , i =0 ;
	     cin>>n>>u>>d;
	     bool nu = false;
	     ll ar[n];
	     FOR(i,n) cin>>ar[i];
	     for(i;i<n-1;i++){
	          if(ar[i+1]>ar[i] && (ar[i+1]-ar[i])<=u){}
	          else if(ar[i+1]<ar[i] && (ar[i]-ar[i+1])<=d){}
	          else if(ar[i+1]<ar[i] && (ar[i]-ar[i+1])>d && !nu){nu = true;}
	          else if(ar[i+1]==ar[i]){}
	          else break;
	     }
	     cout<<i+1<<endl;
	}
	#ifdef ABHI
		timer
	#endif
	return 0;
} 
