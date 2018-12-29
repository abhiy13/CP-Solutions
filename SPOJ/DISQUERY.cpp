//Not Done
//abhiy13
#include <bits/stdc++.h>
  using namespace std;

const int MAXN = 100001;
const int MAXLG = 19;

long long par[MAXN][MAXLG];
long long dist[MAXN];
long long dis[MAXN];

vector <vector <pair<int , long long>>> V(MAXN , vector <pair<int , long long>>());

void dfs(long long v , long long pa = -1 , long long cd = 0){
  par[v][0] = pa;
  dis[v] = cd;
  if(pa + 1){
    dist[v] = dist[pa] + 1;
  }
  for(int i = 1 ; i < MAXLG ; ++i){
    par[v][i] = par[par[v][i - 1]][i - 1];
  }
  for(auto x : V[v]){
    if(pa != x.first){
      dfs(x.first , v , cd + x.second);
    }
  }
}

long long mx , mn;
long long LCA(long long u , long long v){
  if(dist[u] < dist[v]){
    swap(u , v);
  }
  mx = 0 , mn = 10000000;
  for(int i = MAXLG - 1 ; i >= 0 ; --i){
    if(par[u][i] + 1 > 0 && dist[par[u][i]] >= dist[v]){
      mx = max(mx , )
      u = par[u][i];
    }
  }
  if(u == v){
    return u;
  }
  for(int i = MAXLG - 1 ; i >= 0 ; --i){
    if(par[u][i] - par[v][i]){
      v = par[v][i] , u = par[u][i];
    }
  }
  return par[u][0];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  int x , y;
  long long d;
  for(int i = 0 ; i < N - 1 ; ++i) {
    cin >> x >> y >> d;
    x-- , y--;
    V[x].emplace_back(y , d);
    V[y].emplace_back(x , d);
  }
  dfs(0);
  int Q;
  cin >> Q;
  while(Q--) {
    cin >> x >> y;
    x-- , y--;
    cout << dis[x] + dis[y] - 2 * dis[LCA(x , y)] << '\n';
  }
  return 0;
}
