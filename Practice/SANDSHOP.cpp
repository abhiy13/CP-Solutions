/******************************************
*  AUTHOR:         ABHISHEK YADAV         *
*  INSTITUITION:   CHANDIGARH UNIVERSITY  *
******************************************/
#include "bits/stdc++.h"
	using namespace std;
	
#define io std::ios::sync_with_stdio(false);
#define FOR(i,n) for(ll i = 0 ; i < n ; i++)
#define FORR(i,a,b) for(ll i = a ; i < b ; i++)
#define RFOR(i,a,b) for(ll i = a ; i > b ; i--)	
#define ll long long
#define llu unsigned long long
#define PB(x) push_back(x)
#define EB(x) emplace_back(x)
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define SLD(x) scanf("%lld" , &x)
#define SCI(x) scanf("%d" , &x)
#define PLD(x) printf("%lld" , x)
#define PRI(x) printf("%d" , x)
#define SCD(x) scanf("%lf" , &x)
#define inf 1000000000000
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
 
template<typename T, typename U> inline void umin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void umax(T &x, U y) { if(x < y) x = y; }
 
ll knapsack(ll wt[],ll val[], ll n, ll w){
    if(n== 0|| w ==0) return 0;   
    if(wt[n-1]>w) return knapsack(wt, val, n-1, w);
    else return max(knapsack(wt, val, n-1, w), val[n-1] + knapsack(wt,val, n-1, w-wt[n-1]));
}
 
int main(){
	io
	#ifdef ABHI
		ll start_time = clock();
		freopen("input.txt" , "r" , stdin);
	#endif
	int t;
	cin>>t;
	FOR(tt,t){
		ll n,w;
        cin>>n>>w;
        ll val[n],wt[n];
        FOR(i,n){
            cin>>wt[i]>>val[i];
        }
        ll ans = knapsack(wt,val,n,w);
        cout<<ans<<endl;
	}
	#ifdef ABHI
		ll end_time = clock();
		cerr<<"Time Elapsed "<<(double)(end_time - start_time)/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
