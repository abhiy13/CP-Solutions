#include <bits/stdc++.h>

using namespace std;
using Int = long long;

const int nax = 1000010;
pair<int, int> tree[nax << 1];
int ar[nax];

void combine(int idx) {
  if(tree[idx << 1].first > tree[(idx << 1) | 1].first) {
    tree[idx] = tree[idx << 1];
  } else {
    tree[idx] = tree[(idx << 1) | 1];
  }
}

void build(int l, int r, int idx) {
  if(l == r) {
    tree[idx].first = ar[l];
    tree[idx].second = l;
    return;
  }
  int m = (l + r) >> 1;
  build(l, m, idx << 1);
  build(m + 1, r, (idx << 1) | 1);
  combine(idx);
}

void update(int l, int r, int idx, int i, int val) {
  if(l > i || r < i || l > r) return;
  if(l == r) {
    tree[idx].first = val;
    ar[l] = val;
    return;
  }
  int m = (l + r) >> 1;
  update(l, m, idx << 1, i, val);
  update(m + 1, r, (idx << 1) | 1, i, val);
  combine(idx);
}

pair<int, int> query(int l, int r, int s, int e, int idx) {
  if(r < s || l > e || l > r) {
    return make_pair(-1, -1);
  }
  assert(idx >= 1);
  if(s <= l && e >= r) {
    return tree[idx];
  }
  int m = (l + r) >> 1;
  return max(query(l, m, s, e, idx << 1), query(m + 1, r, s, e, (idx << 1) | 1));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> ar[i];
  }
  int q;
  cin >> q;
  char c;
  int l, r;
  build(0, n - 1, 1);
  while(q--) {
    cin >> c >> l >> r;
    if(c == 'Q') {
      l--, r--;
      auto x = query(0, n - 1, l, r, 1);
      update(0, n - 1, 1, x.second, -1);
      auto y = query(0, n - 1, l, r, 1);
      update(0, n - 1, 1, x.second, x.first);
      cout << x.first + y.first << '\n';
    } else {
      update(0, n - 1, 1, --l, r);
    }
  }
  return 0;
}
