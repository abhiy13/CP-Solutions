#include <bits/stdc++.h>

using namespace std;
using Int = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  for(int _t = 1; _t <= tt; _t++) {
    cout << "Caso #" << _t << "\n";
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      g[--v].push_back(--u);
      g[u].push_back(v);
    }
    int timer = 0;
    vector<pair<int, int>> res;
    res.reserve(n);
    vector<int> low(n, -1), tin(n, -1);
    vector<bool> vis(n);
    function<void(int, int)> dfs = [&](int u, int p) {
      low[u] = tin[u] = timer++;
      vis[u] = true;
      for(int x: g[u]) if (x != p) {
        if(vis[x]) low[u] = min(low[u], tin[x]);
        else {
          dfs(x, u);
          low[u] = min(low[u], low[x]);
          if(low[x] > tin[u]) {
            res.emplace_back(min(u + 1, x + 1), max(u + 1, x + 1));
          }
        }
      }
    };
    for(int i = 0; i < n; ++i) {
      if(!vis[i]) dfs(i, -1);
    }
    if(res.empty()) {
      cout << "Sin bloqueos\n";
      continue;
    }
    cout << res.size() << '\n';
    sort(res.begin(), res.end());
    for(auto x: res) {
      cout << x.first << ' ' << x.second << '\n';
    }
  }
  return 0;
}
