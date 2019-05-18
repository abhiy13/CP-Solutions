#include <bits/stdc++.h>

using namespace std;

const int nax = 100010;

long long tree[nax << 2], lazy[nax << 2], ar[nax];

// x << 2 is = x * 4

void push(int l, int r, int idx) {
  if(lazy[idx] != 0) {
    tree[idx] += (r - l + 1) * lazy[idx];
    if(l != r) {
      lazy[idx << 1] += lazy[idx];
      lazy[(idx << 1) | 1] += lazy[idx];
    }
    lazy[idx] = 0;
  }
}

long long merge(long long a, long long b) {
  return a + b;
}

void update(int l, int r, int s, int e, int idx, long long val) {
  push(l, r, idx);
  if(r < s || e < l || l > r) {
    return;
  }
  if(l >= s && e >= r) {
    lazy[idx] += val;
    push(l, r, idx);
    return;
  }
  int mid = (l + r) >> 1;
  update(l, mid, s, e, idx << 1, val);
  update(mid + 1, r, s, e, (idx << 1) | 1, val);
  tree[idx] = merge(tree[idx << 1], tree[(idx << 1) | 1]);
}

long long query(int l, int r, int s, int e, int idx) {
  push(l, r, idx);
  if(r < s || e < l || l > r) {
    return 0;
  }
  if(l >= s && e >= r) {
    return tree[idx];
  }
  int mid = (l + r) >> 1;
  return merge(query(l, mid, s, e, idx << 1), query(mid + 1, r, s, e, (idx << 1) | 1));
}

int main() {
  int tt;
  scanf("%d", &tt);
  while(tt--) {
    int n, q;
    scanf("%d %d", &n, &q);
    memset(tree, 0, sizeof tree);
    memset(lazy, 0, sizeof lazy);
    int t, l, r;
    long long v;
    while(q--) {
      scanf("%d", &t);
      if(t == 0) {
        scanf("%d %d %lld", &l, &r, &v);
        update(0, n - 1, l - 1, r - 1, 1, v);
      } else {
        scanf("%d %d", &l, &r);
        printf("%lld\n", query(0, n - 1, l - 1, r - 1, 1));
      }
    }
  }
  return 0;
}
