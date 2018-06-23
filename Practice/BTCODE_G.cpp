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
 
#define N 100005
 
int parent[N];
int RANK[N];
int col[N];
vector <vi> v(N,vi());
 
int find(int nd){
	if(parent[nd] == nd) return nd;
	return parent[nd] = find(parent[nd]);
}
 
void unionr(int u , int vv){
	int x = find(u);
	int y = find(vv);
	if(RANK[x]==RANK[y]){
		parent[y] = x;
		RANK[x]++;
	}else if(RANK[x] < RANK[y]){
		parent[x] = y;
	}else{
		parent[y] = x;
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int n;
	cin>>n;
	for(int i = 1 ; i <= n ; i++){
		parent[i] = i;
		RANK[i] = 0;
		col[i] = 0;
	}
	int u , vv;
	for(int i = 0 ; i < n-1 ; i++){
		cin>>u>>vv;
		u++,vv++;
		v[u].EB(vv);
		v[vv].EB(u);
	}
	int q;
	cin>>q;
	int t, l , r;
	while(q--){
		cin>>t>>l>>r;
		if(t==1){
			l++;
			col[l] = r;
			int k = v[l].size();
			while(k--){
				if(col[v[l][k]] == r){
					unionr(v[l][k],l);
				}
			}
		}else{
			l++,r++;
			if(find(l) == find(r)) cout<<"YES\n";
			else cout<<"NO\n"; 
		}
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
