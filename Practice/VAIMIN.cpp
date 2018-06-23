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
 
const int N = 4e6 + 10;
ll fact[N] , invfact[N];
 
// add , sub , mul from um_nik and jtnydv25 template
 
vector <pll> blocked_points;
vector <pll> is; 
 
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
 
inline ll inv(int a){ return power(a, MOD - 2);}
 
void precalc(){
    fact[0] = invfact[0] = 1;
    for(int i = 1;i < N; i++) fact[i] = mul(i, fact[i - 1]);
    invfact[N - 1] = inv(fact[N - 1]);
    for(int i = N - 2; i >= 1; i--) invfact[i] = mul(invfact[i + 1], i + 1);
}
 
inline ll gPath(ll x , ll y){
	if(x<0 or y<0) return 0LL;
	return mul(fact[x+y],mul(invfact[x],invfact[y]));
}
 
inline ll rWays(ll x , ll y , ll d){
	return sub(gPath(x,y) , gPath(x-d,y+d));
}
 
 
ll dp[3030];
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	precalc();
	ll p , q , c , m;
	cin>>p>>q>>c>>m;
	if(q==0) c = p;
	if(p-q < c){
		cout<<0<<endl;
		return 0;
	}
	p -= c;
	ll x,  y;
	FOR(i,m){
		cin>>x>>y;
		if(y==0 and x <= c){
			cout<<0<<endl;
			return 0;
		}
		x -= c;
	//	cout<<x<<" "<<y<<endl;
		if(!(x > p or y > q or x < y)){
			blocked_points.push_back({x,y});
	}
	}
	sort(blocked_points.begin(), blocked_points.end());
	blocked_points.push_back({p,q});
	ll n = (ll)blocked_points.size();
	//cout<<n<<endl;
	FOR(i,n){
		dp[i] = rWays(blocked_points[i].F,blocked_points[i].S,blocked_points[i].F-blocked_points[i].S+1);
		FOR(j,i){
			dp[i] = sub(dp[i],mul(dp[j],rWays(blocked_points[i].F - blocked_points[j].F , blocked_points[i].S - blocked_points[j].S , blocked_points[i].F - blocked_points[i].S + 1)));
		}
	}
	cout<<dp[n-1]<<endl;
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
