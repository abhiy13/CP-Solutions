#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int nax = 100010;

#ifdef ABHI
  #include "../debug.h"
  #define _GLIBCXX_DEBUG
#else
  #define debug(...) 42
  #define cerr if(0) cout
#endif

vector<vector<int>> g(nax), gr(nax), G(nax);
vector<int> order, cp;
vector<int> done(nax);

void dfs1(int u) {
  done[u] = true;
  for(int x: g[u]) if(!done[x]) {
    dfs1(x);
  }
  order.push_back(u);
}

void dfs2(int u) {
  done[u] = true;
  cp.push_back(u);
  for(int x: gr[u]) if(!done[x]) {
    dfs2(x);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    gr[v].push_back(u);
  }
  fill(done.begin(), done.begin() + n + 1, false);
  for(int i = 0; i < n; ++i) {
    if(!done[i]) dfs1(i);
  }
  vector<int> par(n);
  vector<bool> is(n);
  fill(done.begin(), done.begin() + n + 1, false);
  reverse(order.begin(), order.end());
  int nos = 0;
  for(int i = 0; i < n; ++i) {
    int u = order[i];
    if(!done[u]) {
      dfs2(u);
      debug(cp);
      nos++;
      int x = cp.front();
      for(int e: cp) {
        par[e] = x;
      }
      is[x] = true;
      cp.clear();
    }
  }
  vector<int> deg(n);
  for(int i = 0; i < n; ++i) {
    for(int x: g[i]) {
      if(par[x] != par[i]) {
        G[par[i]].push_back(par[x]);
        deg[par[x]]++;
      }
    }
  }
  vector<int> res;
  vector<int> stack, ord;
  for(int i = 0; i < n; ++i) {
    if(is[i] && !deg[i]) {
      stack.push_back(i);
    }
  }
  while(!stack.empty()) {
    int u = stack.back();
    stack.pop_back();
    ord.push_back(u);
    for(int x:  G[u]) if(!--deg[x]) {
      stack.push_back(x);
    }
  }
  vector<int> reach(n, 1);
  for(int x: ord) {
    for(int y: G[x]) {
      reach[y] += reach[x];
    }
  }
  for(int i = 0; i < n; ++i) {
    if(reach[par[i]] >= nos) res.push_back(i + 1); 
  }
  sort(res.begin(), res.end());
  cout << res.size() << '\n';
  for(int x: res) {
    cout << x << ' ';
  }
  cout << '\n';
  return 0;
}
