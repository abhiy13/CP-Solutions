/*
 *	Abhishek(abhiy13)
 *	FEB18
 * 	https://www.youtube.com/watch?v=r6zIGXun57U
 *	https://www.youtube.com/watch?v=yANcfPr-EOM
*/
#include "bits/stdc++.h"
	using namespace std;
 
#define		io				std::ios::sync_with_stdio(false);
#define		FOR(i,n)		for(ll i = 0 ; i < n ; i++)
#define		rep(i,a,b)		for(ll i = a ; i < b ; i++)
#define 	rrep(i,a,b)		for(ll i = a ; i > b ; i--)
#define 	timer			cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";	
 
typedef long long ll;
typedef unsigned long long llu;
 
const double mind = -(1e9 + 10);
 
int main(){
	io
	cout.precision(10);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int t;
	cin>>t;
	FOR(tt,t){
		ll n;
		cin>>n;
		ll tunnel[n];
		ll totaldelay = 0;
		FOR(i,n){
			cin>>tunnel[i];
			totaldelay = max(totaldelay,tunnel[i]);
		}
		ll c, d, s;
		cin>>c>>d>>s;
		double ans = totaldelay*(c-1);
		printf("%.25lf\n", ans);
	}
	#ifdef ABHI
		timer
	#endif
	return 0;
} 
