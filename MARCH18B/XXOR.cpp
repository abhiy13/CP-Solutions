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
 
// Reference:::::
// If you want to understand this code please head to : https://www.youtube.com/watch?v=3ZExUX3KE_w&t=1355s
// This Video really helps as explains how to obtain results using Bit Manipulations 
// Video By GKCS :)
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	ll n , t;
	cin>>n>>t;
	vector <ll> ar(n);
	ll ans[n+1][31];
	FOR(i,n) cin>>ar[i];
	FOR(i,31){
		if((1<<i)&ar[0]) ans[0][i] = 1;
		else ans[0][i] = 0;
	}
	FORR(i,1,n) FOR(j,31){
		if((1<<j)&ar[i]) ans[i][j] = 1 + ans[i-1][j];
		else ans[i][j] = ans[i-1][j];
	}
	ll l , r , query = 0;
	FOR(tt,t){
		query = 0;
		cin>>l>>r;
		l--,r--;
		if(l>r) swap(l,r);
		FOR(i,31){
			if(l==0){
				if(ans[r][i] < ((r+1) - ans[r][i])) query |= (1<<i);
			}else{
				ll temp = ans[r][i] , t2 = ans[l-1][i];
				if((temp-t2)<(r-l+1-temp+t2)) query |= (1<<i);
			}
		}
		cout<<query<<endl;
	}
	#ifdef ABHI
		timer
	#endif
	return 0;
} 
