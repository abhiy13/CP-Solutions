/******************************************
*  AUTHOR:         ABHISHEK YADAV         *
*  INSTITUITION:   CHANDIGARH UNIVERSITY  *
******************************************/
#include "bits/stdc++.h"
	using namespace std;
	
#define io std::ios::sync_with_stdio(false);cin.tie(NULL);
#define FOR(i,n) for(ll i = 0 ; i < n ; i++)
#define FORR(i,a,b) for(ll i = a ; i < b ; i++)
#define RFOR(i,a,b) for(ll i = a ; i > b ; i--)	
#define ll long long
#define llu unsigned long long
#define PB(x) push_back(x)
#define EB(x) emplace_back(x)
#define MP(a,b) make_pair(a,b)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define slld(x) scanf("%lld" , &x)
#define sid(x) scanf("%d" , &x) 
#define sllu(x) scanf("%llu" , &x)
#define plld(x) printf("%lld\n" , x)
#define pid(x) printf("%d\n" , x)
#define pllu(x) printf("%llu\n" , x)
 
template<typename T, typename U> inline void umin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void umax(T &x, U y) { if(x < y) x = y; }
 
const ll inf =  100000000000;
 
int main(){
	#ifdef ABHI
	//	freopen("input.txt" , "r" , stdin);
	#endif
	int t;
	sid(t);
	FOR(tt,t){
		ll n;
		slld(n);
		unordered_map <double , set<double>> mp;
		ll a , b , c;
		FOR(i,n){
			slld(a);slld(b);slld(c);
			double m , I;
			if(b==0){
				m = inf;
				I = -(double)c/a;
			}else{
				m = -(double)a/b;
				I = -(double)c/a;
			}
			mp[m].insert(I);
		}
		ll res = 0;
		for(auto p : mp){
			umax(res,p.second.size());
		}
		plld(res);
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
