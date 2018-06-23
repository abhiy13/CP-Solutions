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
#define debug(x) cout<<x<<" ";
#define inf 1000000000000
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
 
template<typename T, typename U> inline void umin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void umax(T &x, U y) { if(x < y) x = y; }
 
 
void multiply(ll a[2][2], ll b[2][2]){
    int ans[2][2];
    FOR(i,2) FOR(j,2){
        ans[i][j]=0;
        FOR(k,2) ans[i][j] = (ans[i][j]+(a[i][k]*b[k][j])%MOD)%MOD;
    }
 
    FOR(i,2) FOR(j,2) a[i][j] = ans[i][j];
}
 
ll matrixpower(ll b){
    ll a[2][2];
    a[0][0]=2;
    a[0][1]=3;
    a[1][0]=1;
    a[1][1]=0;
    ll c[][2] = {{1,0},{0,1}};
    while(b){
        if(b&1) multiply(c,a);
        multiply(a,a);
        b>>=1;
    }
    ll answer=(5*c[0][0])%MOD + (2*c[0][1])%MOD;
    answer%=MOD;
    return answer;
}
 
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
		if(n==0) cout<<2<<endl;
		else if(n==1) cout<<5<<endl;
		else{
			cout<<matrixpower(n-1)<<endl;
		}
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
