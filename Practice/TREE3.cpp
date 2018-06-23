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
#define N 2000
 
vector <vector<ll>> ar;
vector <bool> vis;
vector <int> used;
vector <ll> v[N];
ll kk = 0;
 
 
void solve(int u){
	set <ll> S;
	for(int i = 0 ; i < (ll)ar[u].size() ; i++){
		if(used[ar[u][i]] < 1) S.insert(ar[u][i]);
	}
	if(S.size() >= 3){
		ll lp = 0;
		v[kk].PB(u);
		used[u]++;
		for(auto &p : S){
			v[kk].PB(p);
			used[p]++;
			lp++;
			if(lp == 3) break;
		}
		kk++;
	}
	for(auto &p : ar[u]){ 
		if(!vis[p]){
			if(!vis[p]){
				vis[p] = true;
				solve(p);
			}
		}
	}
}
 
int main(){
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int T;
	cin>>T;
	while(T--){
		ll n , h;
		cin>>n;
		ar.resize(n+1,vector<ll>());
		for(int i = 0 ; i < n-1 ; i++){
			ll x  ,y ;
			cin>>x>>y;
			ar[x].PB(y);
			ar[y].PB(x);
		}
		vis.resize(n+1,false);
		kk = 0;
		used.resize(n+1,0);
		for(int i = 1 ; i <= n ; i++){
			if(!vis[i]){
				solve(i);
			}
		}
		if(kk != (n-1)/3){
			cout<<"NO\n";
		}else{
			cout<<"YES\n";
			for(int i = 0; i < (n-1)/3 ; i++){
				cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<" "<<v[i][3]<<endl;
			}
		}
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
