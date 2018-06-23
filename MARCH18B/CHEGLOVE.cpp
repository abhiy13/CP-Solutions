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
	string ans[] = {"front", "back", "both","none"};
	FOR(tt,t){
		ll n;
		cin>>n;
		vector <ll> a(n) , b(n);
		FOR(i,n) cin>>a[i];
		FOR(i,n) cin>>b[i];
		ll f = 0 , bb =  0;
		FOR(i,n){
			if(a[i] <= b[i]) f++;
			if(a[i] <= b[n-i-1]) bb++;
		}
		bool k = f==n;
		bool p = bb==n;
		if(k and p) cout<<ans[2]<<endl;
		else if(k) cout<<ans[0]<<endl;
		else if(p) cout<<ans[1]<<endl;
		else cout<<ans[3]<<endl;
	}
	#ifdef ABHI
		timer
	#endif
	return 0;
} 
