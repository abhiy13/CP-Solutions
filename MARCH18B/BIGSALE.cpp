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
	FOR(tt,t){
		ll n;
		cin>>n;
		double a , b , c;
		double res = 0.0;
		FOR(i,n){
			cin>>a>>b>>c;
			c/=100;
			//cout<<c<<endl;
			double k = (double)a + ((double)a*c);
			double h = k*c;
			k -= h;
			//cout<<k<<b<<endl;
			res += (double)(a-k)*(double)b; 
			//cout<<res<<endl;
		}
		printf("%.20lf\n" , res);
	}
	#ifdef ABHI
		timer
	#endif
	return 0;
} 
