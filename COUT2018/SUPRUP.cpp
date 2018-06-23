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
		ll n , m;
		ll maxx = 0;
		cin>>n>>m;
		char ar[n][m];
		memset(ar,' ',sizeof(ar));
		ll kk = 0 , mm = 0, tsum = 1;
		FOR(i,n) FOR(j,m) cin>>ar[i][j];
		//FOR(i,n){ FOR(j,m){ cout<<ar[i][j];} cout<<endl;}
		FOR(i,n) FOR(j,m){
			tsum = 1;
			kk = i;
			mm = j;
			while(ar[kk][mm] == ar[kk][mm+1] && mm < m-1){
				mm++;
				tsum++;
			}
			maxx = max(maxx,tsum);
			tsum = 1;
			kk = i;
			mm = j;
			while(ar[kk][mm] == ar[kk+1][mm] && kk < n-1){
				kk++;
				tsum++;
			}
			maxx = max(maxx,tsum);
		}
		cout<<maxx<<endl;
	}
	#ifdef ABHI
		timer
	#endif
	return 0;
}  
