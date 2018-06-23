/*
 *	Abhishek(abhiy13)
 *	Chandigarh University
*/
 
#include "bits/stdc++.h"
	using namespace std;
 
#define		io				std::ios::sync_with_stdio(false);
#define		FOR(i,n)		     for(int i = 0 ; i < n ; i++)
#define		rep(i,a,b)		for(int i = a ; i < b ; i++)
#define   	rrep(i,a,b)		for(int i = a ; i > b ; i--)
#define 	     timer			cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";	
 
typedef long long ll;
typedef unsigned long long llu;
 
ll hpo(ll n){
   ll p = (ll)log2(n);
   return (ll)pow(2, p); 
}
 
bool is(ll x){
  return x && (!(x&(x-1)));
}
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int t;
	cin>>t;
	while(t--){
	     ll n;
	     int i = 1;
	     cin>>n;
	     while(1){
	          if(!is(n)){
	               n -= hpo(n); 
	          }else{
	               n -= n/2;
	          }
	          i*=-1;
	          if(n==1) break;
	     }
	     if(i==1) cout<<"Harry\n";
	     else cout<<"Cisco\n";
	}
	#ifdef ABHI
		timer
	#endif
	return 0;
} 
