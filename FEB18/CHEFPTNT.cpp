/*
 *	Abhishek(abhiy13)
 *	FEB18
*/
 
#include "bits/stdc++.h"
	using namespace std;
 
#define		io				std::ios::sync_with_stdio(false);
#define		FOR(i,n)		for(int i = 0 ; i < n ; i++)
#define		rep(i,a,b)		for(int i = a ; i < b ; i++)
#define 	rrep(i,a,b)		for(int i = a ; i > b ; i--)
#define 	timer			cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";	
 
typedef long long ll;
typedef unsigned long long llu;
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int t;
	cin>>t;
	FOR(tt,t){
		ll n , m , x , k;
		cin>>n>>m>>k>>x;
		string s;
		cin>>s;
		ll o=0,e=0;
		for(ll i = 0 ; i < x ; i++) (s[i]=='O')?o++:e++;
		int ans=0;
		/*if(k<=o){
			ans+=o;
			o-=k;
		}
		if(k<=e){
			ans+=e;
			e-=k;
		}
		if(ans>=n){
			cout<<2<<endl;
		}*/
		for(int i = 1 ; i <= m ; i++){
			if(i&1){
				if((o-k)>0) {o-=k;ans+=k;} 
				else {ans+=o;o=0;}
			}else{
				if((e-k)>0) {e-=k;ans+=k;}
				else {ans+=e;e=0;}
			}
		}
		if(ans>=n) cout<<"yes\n";
		else cout<<"no\n";
	}
	#ifdef ABHI
		timer
	#endif
	return 0;
} 
