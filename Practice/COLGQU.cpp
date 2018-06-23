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
 
//Union Rank and Path Compression 
 
struct UnionSet{
	vi parent , RANK;
	void init(int n = 105){
		parent.resize(n+1,0);
		RANK.resize(n+1,0);
		for(int i = 1 ; i <= n ; i++){
			parent[i] = i;
		}
	}
 
	int find(int nd){
		if(parent[nd] == nd) return nd;
		return parent[nd] = find(parent[nd]);
	}
 
	void unionr(int u , int vv){
		if(has(u,vv)) return;
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
 
	bool has(int a , int b){
		return find(a) == find(b);
	}
};
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	ll n , k;	
	cin>>n>>k;
	UnionSet S[106];
	for(int i = 0 ; i <= 105 ; i++) S[i].init((int)n);
	int a , b , c;
	for(int i = 0 ;i < k ; i++){
		cin>>a>>b>>c;
		S[c].unionr(a,b);
	}
	int q;
	cin>>q;
	int u , v;
	while(q--){
		cin>>u>>v;
		int ans =  0;
		for(int i = 1 ; i <= 105 ; i++){
			if(S[i].has(u,v)) ans++;
		}
		cout<<ans<<endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
