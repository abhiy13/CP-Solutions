/*
 *	Abhishek(abhiy13)
 *	MARCH18
 * 	https://www.youtube.com/watch?v=r6zIGXun57U
*/
 
#include "bits/stdc++.h"
	using namespace std;
 
#define	io				std::ios::sync_with_stdio(false);
#define	FOR(i,n)		for(ll i = 0 ; i < n ; i++)
#define	FORR(i,a,b)		for(ll i = a ; i < b ; i++)
#define RFOR(i,a,b)		for(ll i = a ; i > b ; i--)
#define timer			cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";	
#define all(x)			begin(x),end(x)
#define SZ(x) x.size()
 
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int t;
	cin>>t;
	int s[26] = {0};
	s['a'-'a'] = 1;
	s['e'-'a'] = 1;
	s['i'-'a'] = 1;
	s['o' - 'a'] = 1;
	s['u' - 'a'] = 1;
	string ms , ss;
	ll maxcnt = 0 , currcnt = 0; 
	FOR(tt,t){
		int mpp[26] = {0};
		currcnt = 0;
		cin>>ss;
		for(char c : ss){
			if(s[c-'a']) mpp[c-'a']++;	
			if(mpp['a'-'a'] >= 1 && mpp['e'-'a'] >= 1 && mpp['i'-'a'] >= 1 && mpp['o' - 'a'] >= 1 && mpp['u' - 'a'] >= 1) break;
		}
		if(mpp['a'-'a'] >= 1 && mpp['e'-'a'] >= 1 && mpp['i'-'a'] >= 1 && mpp['o' - 'a'] >= 1 && mpp['u' - 'a'] >= 1)
			cout<<ss<<endl;
	}
	//cout<<ms<<endl;
	#ifdef ABHI
		timer
	#endif
	return 0;
}   
