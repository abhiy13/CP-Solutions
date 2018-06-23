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
		string s;
		cin>>s;
		ll n = s.size();
		int ii , h , f , c;
		int ans = 0;
		for(int i = 0 ; i < n ; i++){
			if(s[i]=='c' || s[i] == 'h' || s[i]=='e' || s[i]=='f'){
				ii = 0;h=0;f=0;c=0;
				for(int j = i-2 ; j < i+2 ; j++){
					if(s[j]=='c') c++;
					else if(s[j]=='h') h++;
					else if(s[j]=='e') ii++;
					else if(s[j]=='f') f++;
				}
				while(c>0 && h>0 && ii>0 && f>0){
					ans++;
					c--;h--;ii--;f--;
				}
			}
		}
		if(ans==0) cout<<"normal\n";
		else cout<<"lovely "<<ans<<endl;
	}
	#ifdef ABHI
		timer
	#endif
	return 0;
} 
