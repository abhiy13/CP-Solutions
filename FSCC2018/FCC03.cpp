/*
 *	Abhishek(abhiy13)
 *	Chandigarh University
*/
 
#include "bits/stdc++.h"
	using namespace std;
 
#define		io				std::ios::sync_with_stdio(false);
#define		FOR(i,n)		     for(int i = 0 ; i < n ; i++)
#define		FORR(i,a,b)		for(int i = a ; i < b ; i++)
#define   	rep(i,a,b)		for(int i = a ; i > b ; i--)
#define 	     timer			cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";	
 
typedef long long ll;
typedef unsigned long long llu;
 
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
	     ll ar[n];
	     int pp = 1;
	     FOR(i,n) cin>>ar[i];
	     while(1){
	          ll k = distance(ar,max_element(ar,ar+n));
	          FORR(i,k,n) ar[i] = -1000;
	          pp*=-1;
	          if(std::count(ar,ar+n,-1000)==n) break;
	     }
	     if(pp==1) cout<<"OLIVER\n";
	     else cout<<"FLASH\n";
	}
	#ifdef ABHI
		timer
	#endif
	return 0;
} 
