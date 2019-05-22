#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int nax = 80050;

#ifdef ABHI
  #include "../debug.h"
  #define _GLIBCXX_DEBUG
#else
  #define debug(...) 42
  #define cerr if(0) cout
#endif

vector<pair<int, int>> tree(nax << 2);
vector<int> cnt(nax + 10);

void clear() {
  fill(tree.begin(), tree.end(), make_pair(0, 0));
  fill(cnt.begin(), cnt.end(), 0);
}

void push(int x, int l, int r) {
  if(tree[x].second != 0) {
    tree[x].first = tree[x].second;
    if(l != r) {
      tree[x << 1].second = tree[x].second;
      tree[(x << 1) | 1].second = tree[x].second;
    }
    tree[x].second = 0;
  }
}

void update(int l, int r, int s, int e, int v, int x) {
  if(r < s || l > e || l > r) return;
  push(x, l, r);
  if(l >= s && r <= e) {
    tree[x].second = v;
    push(x, l, r);
    return;
  }
  int m = (l + r) >> 1;
  update(l, m, s, e, v, x << 1);
  update(m + 1, r, s, e, v, (x << 1) | 1);
}

int query(int l, int r, int i, int x) {
  push(x, l, r);
  if(l == r) {
    assert(tree[x].second == 0);
    return tree[x].first;
  }
  int m = (l + r) >> 1;
  if(i <= m) {
    return query(l, m, i, x << 1);
  } else {
    return query(m + 1, r, i, (x << 1) | 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while(tt--) {
    clear();
    int n; cin >> n;
    map<int, int> mp;
    vector<pair<int, int>> ar(n);
    for(int i = 0; i < n; ++i) {
      cin >> ar[i].first >> ar[i].second;
      mp[ar[i].first];
      mp[ar[i].second];
    }
    int c = 0;
    for(auto &x: mp) {
      x.second = c++;
    }
    int col = 1;
    for(auto &x: ar) {
      x.first = mp[x.first];
      x.second = mp[x.second];
      update(0, (n << 1), x.first, x.second, col++, 1);
    }
    int res = 0;
    for(int i = 0; i < c; ++i) {
      int x = query(0, (n << 1), i, 1);
      if(x == 0) continue;
      cnt[x]++;
      if(cnt[x] == 1) res++;
    }
    cout << res << '\n';
  }  
  return 0;
}
