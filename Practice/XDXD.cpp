/******************************************
*  AUTHOR:         ABHISHEK YADAV         *
*  INSTITUITION:   CHANDIGARH UNIVERSITY  *
******************************************/
#include <bits/stdc++.h>
	using namespace std;
 
typedef long long ll;
 
#define inf 100000000000000000
#define N 100005
 
vector <pair<ll,ll>> v[N];
vector<ll> ps(N,0) , one(N,0) , two(N,0);
 
inline ll in(){
	ll k; cin>>k;
	return k;
}
 
void dijkstra(ll S){
	ll u , vv , c , w;
	priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> Q;
	Q.push({0,S});
	one[S] = 0;
	while(!Q.empty()){
		u = Q.top().second;
		c = Q.top().first;
		Q.pop();
		if(one[u] < c){
			continue;
		}
		for(int i = 0 ; i <v[u].size() ; i++){
			w = v[u][i].second;
			vv = v[u][i].first;
			if(one[vv] > one[u]+w){
				one[vv] = one[u] + w;
				Q.push({one[vv],vv});
			}
		}
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int T;
	cin>>T;
	while(T--){
		int n  , dd , p , s , f;
		cin>>n>>dd>>p>>s>>f;
		for(int i = 0; i < n+1 ; i++){
			v[i].clear();
		}
		for(int i = 0 ;i < n+2 ; i++){
			ps[i] = one[i] = 0;
		}
		for(int i = 0 ; i < p ; i++){
			ps[in()] = 1;
		}
		int u , vv , w;
		for(int i = 0 ;i < n-1 ; i++){
			cin>>u>>vv>>w;
			v[u].push_back({vv,w});
			v[vv].push_back({u,w});
		}
		for(int i = 0 ; i < n+1 ; i++) one[i] = inf;
		dijkstra(s);
		for(int i = 0 ; i < n+1 ; i++) two[i] = one[i];
		for(int i = 0 ; i < n+1 ; i++) one[i] = inf;
		dijkstra(f);
		ll res = inf;
		for(int i = 1 ; i <= n ; i++){
			if(ps[i] and two[i] <= dd){
				res = min(res , one[i]+two[i]);
			}
		}
		if(res == inf) cout<<-1<<endl;
		else cout<<res<<endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
