#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int nax = 10010;
const int LG = 19;

vector<vector<pair<int, int>>> g(nax);
vector<int> d(nax);
vector<vector<int>> par(nax, vector<int>(LG, -1));
vector<int> dist(nax);
int n;

void dfs(int u, int p = -1, int de = 0) {
  par[u][0] = p;
  d[u] = de;
  for(auto x: g[u]) if (x.first != p) {
    dist[x.first] = dist[u] + x.second;
    dfs(x.first, u, de + 1);
  }
}

void precompute() {
  for(int k = 1; k < LG; ++k) {
    for(int i = 0; i < n; ++i) {
      if(par[i][k - 1] != -1) {
        par[i][k] = par[par[i][k - 1]][k - 1];
      }
    }
  }
}

int walk(int u, int k) {
  for(int i = 0; i < LG && u != -1; ++i) {
    if((k >> i) & 1) {
      u = par[u][i];
    }
  }
  return u;
}

int LCA(int u, int v) {
  if(d[u] > d[v]) swap(u, v);
  v = walk(v, d[v] - d[u]);
  if(u == v) {
    return v;
  }
  for(int i = LG - 1; i >= 0; --i) {
    if(par[u][i] != par[v][i]) {
      u = par[u][i];
      v = par[v][i];
    }
  }
  return par[u][0];
}

int diste(int u, int v) {
  return dist[u] + dist[v] - 2 * dist[LCA(u, v)];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while(tt--) {
    cin >> n;
    for(int i = 0; i < n; ++i) {
      g[i].clear();
      fill(par[i].begin(), par[i].end(), -1);
    }
    dist[0] = 0;
    for(int i = 0; i < n - 1; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      --u, --v;
      g[u].emplace_back(v, w);
      g[v].emplace_back(u, w);
    }
    dfs(0);
    precompute();
    string q;
    int u, v, k;
    while(1) {
      cin >> q;
      if(q == "DONE") break;
      if(q == "DIST") {
        cin >> u >> v;
        --u, --v;
        cout << diste(u, v) << '\n';
      } else {
        cin >> u >> v >> k;
        --u, --v;
        int L = LCA(u, v);
        int ds = d[u] - d[L];
        k--;
        assert(k >= 0);
        if(ds >= k) {
          cout << walk(u, k) + 1 << '\n';
        } else {
          k -= ds;
          int de = d[v] - d[L];
          cout << walk(v, de - k) + 1 << '\n';
        }
      }
    }
  }
  return 0;
}
