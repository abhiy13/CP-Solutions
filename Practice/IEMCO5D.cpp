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
 
ll fenw[123456];
void update(ll i , ll val , ll n){
	while(i<=n){
		fenw[i] += val;
		i += (i&(-i)); 
	}
}
 
ll query(ll i){
	ll r = 0;
	while(i){
		r += fenw[i];
		i -= (i&(-i));
	}
	return r;
}
 
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int ttt;
	cin>>ttt;
	FOR(tt,ttt){
		memset(fenw,0,sizeof(fenw));
		ll n , q , rr;
		cin>>n>>q;
		FORR(i,1,n+1){
			cin>>rr;
			update(i,rr,n);
		}
		ll t , x  , M , L , R;
		while(q--){
			cin>>t;
			if(t==1){
				cin>>x>>M;
				update(x,M,n);
			}else{
				cin>>x>>M>>L>>R;
				ll res = query(min(n,x+R)) - query(max(1LL,x-L)-1);
				if(x+R > n){
					res += query(x+R-n);
				}
				if(x-L < 1){
					res += query(n) - query(n+(x-L)-1);
				}
				if(res >= M) cout<<"YES\n";
				else cout<<"NO\n";
			}
		}
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
