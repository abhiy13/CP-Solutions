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
 
ll counter;
 
void dfs(bool *visited , vector <vector <ll> > ar , int node){
	visited[node] = true;
	for(auto p : ar[node]){
		if(!visited[p]){
			counter++;
			dfs(visited,ar,p);
		}
	}
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
		unordered_map <string,ll> mp;
		string s1 , s2;
		ll k = 1;
		vector <vector <ll> > ar(100000,vector<ll>());
		FOR(i,n){
			cin>>s1>>s2;
			ll u , v;
			if(mp[s1]==0){
				mp[s1] = k++;
			}
			if(mp[s2]==0){
				mp[s2] = k++;
			}
			u = mp[s1] , v = mp[s2];
			ar[u].PB(v);
			ar[v].PB(u);
		}
		bool visited[k];
		//for(auto k : mp){
		//	cout<<k.first << " " << mp[k.first]<<" ";
		//}
		//cout<<endl;
		memset(visited,false,sizeof(visited));
		ll ccon = 0 , res = -10000;
		for(int i = 1 ; i < k ; i++){
			if(!visited[i]){
				//cout<<i<<" ";
				counter = 1;
				dfs(visited,ar,i);
				res = max(res , counter);
				ccon++;
			}
		}
		//cout<<endl;
		cout<<ccon<<" "<<res<<endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
