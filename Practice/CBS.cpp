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
 
//fact and inv fact from jtnydv25 and um_nik's templates
 
const int N = 100005;
ll fact[N] , invfact[N];
 
inline ll add(ll x, ll y){ x += y; if(x >= MOD) x -= MOD; return x;}
inline ll sub(ll x, ll y){ x -= y; if(x < 0) x += MOD; return x;}
inline ll mul(ll x, ll y){ return (((ll) x) * y) % MOD;}
inline ll power(ll a, ll b){
    ll x = 1 % MOD;
    while(b){
        if(b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}
 
inline ll inv(ll a){ return power(a, MOD - 2LL);}
 
void precalc(){
    fact[0] = invfact[0] = 1;
    for(int i = 1;i < N; i++) fact[i] = mul(i, fact[i - 1]);
    invfact[N - 1] = inv(fact[N - 1]);
    for(int i = N - 2; i >= 1; i--) invfact[i] = mul(invfact[i + 1], i + 1);
    return;
}
 
ll C(ll n, ll r)
{
    if(r < 0LL)
        return 0LL;
    ll ans = fact[n];
    ans = (ans*invfact[n-r])%MOD;
    ans = (ans*invfact[r])%MOD;
    return ans;
}
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	precalc();
	int t;
	cin>>t;
	FOR(tt,t){
		ll n , k;
		cin>>n>>k;
		n/=2;
		if(k>(n/2)){
			cout<<1<<endl;
			continue;
		}			
		ll total = (C(2*n,n)-C(2*n,n+1) + MOD)%MOD;
		ll res = 0LL , temp;
		FOR(i,k+1){
			temp = (C(n,i) - C(n,i-1) + MOD) % MOD;
			temp = (temp*temp)%MOD;
			res = (res+temp)%MOD;
		}
		res = (res*inv(total))%MOD;
		cout<<res<<endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
