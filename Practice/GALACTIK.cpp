#include "bits/stdc++.h"
	using namespace std;
 
#define PB(x) push_back(x)
#define EB(x) emplace_back(x)
#define F first
#define S second
 
#define TRACE
 
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
 
typedef long long ll;
typedef pair <int,int> pii;
typedef vector <int> vi;
 
#define inf 100000000
 
vector <bool> vis;
vector <vi> e;
vi cost;
int res;
 
void dfs(int s){
	vis[s] = true;	
	res = min(res,cost[s]);		
	for(auto &a : e[s]){
		if(!vis[a]){
			dfs(a);
		}
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int n  , m ;
	cin>>n>>m;
	swap(n,m);
	e.resize(m+1,vi());
	vis.resize(m+1,false);
	cost.resize(m+1,0);
	int u , v;
	for(int i = 0 ; i < n ; i++){
		cin>>u>>v;
		e[u].EB(v);
		e[v].EB(u);
	}
	for(int i = 0 ; i < m ; i++){
		cin>>cost[i+1];
		if(cost[i+1] < 0) cost[i+1] = inf;
	}
	int ans = 0 , count = 0 , superminimum = inf; bool ok = true;
	for(int i = 1 ; i <= m ; i++){
		if(!vis[i]){
			res = inf;
			dfs(i);
			if(res==inf){
				ok = false;
			}else{
				ans += res;
			}
			superminimum = min(superminimum,res);
			count++;
		}
	}
	if(!ok) cout<<((count==1)?0:-1)<<endl;
	else cout<<ans + (count-2)*superminimum<<endl;
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
