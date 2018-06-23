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
 
typedef long long ll;
typedef unsigned long long llu;
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
	     int n;
	     cin>>n;
	     int ar[n];
	     for(int i = 0 ; i < n ; i++){
	          cin>>ar[i];
	     }
	     FOR(i,n){
	          if(ar[i]%10 != 7) cout<<ar[i]<<" ";
	     }
	     cout<<endl;
	}
	#ifdef ABHI
		timer
	#endif
	return 0;
} 
