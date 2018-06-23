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
 
 
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int t;
	cin>>t;
	vector <set<ll>> vec(123456);
	ll done[123456] , p[123456];
	FOR(tt,t){
		ll n , m;
		cin>>n>>m;
		ll a, b;
		memset(done,0,sizeof(done));
		memset(p,0,sizeof(p));
		FOR(i,n+11){
			vec[i].clear();
		}
		FOR(i,m){
			cin>>a>>b;
			vec[a].insert(b);
			vec[b].insert(a);
		}
		FOR(i,n){
			cin>>p[i];
		}
		ll flag = 1;
		//First time using lambda functions XP
		function<ll(ll,ll)> dfs = [&](ll curr,ll pos){
			if(pos==n) return 0;
			done[curr] = 1;
			if(!flag) return 0;
			if(vec[curr].find(p[pos]) != vec[curr].end()){
				dfs(p[pos],pos+1);
			}else{
				for(auto c : vec[curr]){
					if(!done[c]){
						flag = 0;
					}
				}
			}
			return 0;
		};	
		dfs(p[0],1);
		if(flag==1) cout<<"YES\n";
		else cout<<"NO\n";
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
