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
 
ll n , m  , c;
 
ll fenw[1000005];
void update(ll i , ll val){
	while(i<=n){
		fenw[i] += val;
		i += i&-i; 
	}
}
 
ll query(ll i){
	ll r = 0;
	while(i){
		r += fenw[i];
		i -= i&-i;
	}
	return r;
}
 
inline void init(){
	memset(fenw,0,sizeof(fenw));
}
 
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	init();
	cin>>n>>m>>c;
	char cc;
	while(m--){
		cin>>cc;
		if(cc=='Q'){
			ll r;
			cin>>r;
			cout<<query(r)+c<<endl;
		}else{
			ll r , l , k;
			cin>>l>>r>>k;
			update(l,k);
			update(r+1,-k);
		}
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
