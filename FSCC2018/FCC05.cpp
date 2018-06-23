/*
 *	Abhishek(abhiy13)
 *	Chandigarh University
*/
 
#include "bits/stdc++.h"
	using namespace std;
 
#define		io				std::ios::sync_with_stdio(false);
#define		FOR(i,n)		     for(int i = 0 ; i < n ; i++)
#define		FORR(i,a,b)		for(int i = a ; i < b ; i++)
#define   	rrep(i,a,b)		for(int i = a ; i > b ; i--)
#define 	     timer			cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";	
 
typedef long long ll;
typedef unsigned long long llu;
const int maxn =  1e5+10;
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
         int n, m;
         cin>>n>>m;
         ll a[maxn];
         FORR(i,1,n+1){ 
             cin>>a[i]; 
         }
         sort(a+1,a+n+1);
         int ans = 0, i=1;
         while(i<=n){
             int kk = a[i] + m;
             int j=i;
             ans = ans + 1;
             while(j<=n and a[j]<=kk){
                 i = j;
                 j++;
             }
             
             kk = a[i]+m;
             j = i;
             while(j<=n and a[j]<=kk){
                 i = j;
                 j++;
             }
             i = i + 1;
         }
         cout<<ans<<endl;
	#ifdef ABHI
		timer
	#endif
	return 0;
} 
