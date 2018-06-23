#include "bits/stdc++.h"
	using namespace std;	
#define io std::ios::sync_with_stdio(false);
#define FOR(i,n) for(ll i = 0 ; i < n ; i++)
#define ll long long 
 
inline ll gcd(ll a , ll b){
     if(!a) return b;
     else return gcd(b%a,a);
}
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int t;
	cin>>t;
	FOR(tt,t){
	     ll a;
	     string s;
	     cin>>a>>s;
	     if(a==0){
	          cout<<s<<endl;
	          continue;
	     }
	     ll n = s.length();
	     ll res = 0;
	     FOR(i,n){
	          res = (res*10 + s[i] - '0') % a;    
	          //cout<<res<<" ";
	     }
	     /*if(res==0){
	          cout<<"YS"<<endl;
	          continue;
	     }*/
	     cout<<gcd(res,a)<<endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
}  
