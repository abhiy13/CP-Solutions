/*
 *	Abhishek(abhiy13)
 *	FEB18
 * 	https://www.youtube.com/watch?v=r6zIGXun57U
*/
 
#include "bits/stdc++.h"
	using namespace std;
 
#define		io				std::ios::sync_with_stdio(false);
#define		FOR(i,n)		for(ll i = 0 ; i < n ; i++)
#define		rep(i,a,b)		for(ll i = a ; i < b ; i++)
#define 	rrep(i,a,b)		for(ll i = a ; i > b ; i--)
#define 	timer			cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";	
#define 	all(x)			(x.begin(),x.end())
#define 	SZ(x)			(x.size())
 
typedef long long ll;
typedef unsigned long long llu;
const int md = 1e9+7;
 
ll mypowercalc(ll n , ll k , ll p){
	ll r = 1;
	for(;k;k>>=1){
		if(k&1) r=(r*n)%p;
		n=(n*n)%p;
	}
	return r;
}
ll inverse(ll a , ll p = md){
	ll kk = mypowercalc(a,p-2,p);
	return kk;
}
 
ll l , d ,t , cs; 
 
void mk(ll one[2][2] , ll two[2][2]){
	ll res[3][3];
	memset(res,0,sizeof(res));
	FOR(i,2) FOR(j,2){
		res[i][j] = 0;
		FOR(k,2){
			res[i][j] = (res[i][j]%md + (one[i][k]*two[k][j])%md)%md;
		}
	}
	FOR(i,2) FOR(j,2) one[i][j] = res[i][j];
}
 
ll per(ll am[2][2] , ll n){
	ll na[2][2];
	na[0][0] = (cs*2)%md;
	na[0][1] = md-1;
	na[1][0] = 1;
	na[1][1] = 0;
	if(n==1) return ((cs*am[0][0])%md + am[0][1])%md;
	per(am,n/2);
	mk(am,am);
	if(n%2!=0) mk(am,na);
	return ((cs*am[0][0])%md + am[0][1])%md; 
}
 
ll kill(ll n){
	ll am[2][2] = {{(2*cs)%md,md-1} , {1,0}};
	if(++n==2) return cs;
	return per(am,n-2);
}
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int ttt;
	cin>>ttt;
	FOR(tt,ttt){
		cin>>l>>d>>t;
		cs = (d*inverse(l))%md;
		ll ans = kill(t);
		ll fres = (ans*l)%md;
		cout<<fres<<endl;
	}
	#ifdef ABHI
		timer
	#endif
	return 0;
} 
