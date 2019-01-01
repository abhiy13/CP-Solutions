//abhiy13
#include <bits/stdc++.h>

using namespace std;

const int MN = 500050;
struct Node {
  int x;
  Node* l, *r;
  Node(Node* _l = NULL , Node* _r = NULL , int _x = 0) {
    l = _l;
    r = _r;
    x = _x;
  }
};

int ar[MN];
Node* versions[MN];

void build(Node* tree , int l , int r) {
  if(r < l) return;
  if(l == r) {
    tree->x = 0;
    return;
  }
  int mid = (l + r) >> 1;
  tree->l = new Node();
  tree->r = new Node();
  build(tree->l , l , mid);
  build(tree->r , mid + 1 , r);
  tree->x = tree->l->x + tree->r->x;
}

void update(Node* old, Node* curr, int l , int r , int idx , int val) {
  if(idx < l || idx > r || r < l) return;
  if(l == r) {
   curr->x = old->x + val;
   return;
  }
  int mid = (l + r) >> 1;
  if(idx <= mid) {
   curr->r = old->r;
   curr->l = new Node();
   update(old->l , curr->l , l , mid , idx , val);
  } else {
   curr->l = old->l;
   curr->r = new Node();
   update(old->r , curr->r , mid + 1 , r , idx , val);
  }
  curr->x = curr->l->x + curr->r->x;
}

int query(Node* root , int l , int r , int lo , int hi) {
  if(lo > r || hi < l || r < l) return 0;
  if(root == NULL) return 0;
  if(lo <= l && r <= hi) {
    return root->x;
  }
  int mid = (l + r) >> 1;
  int a = query(root->l , l , mid , lo , hi);
  int b = query(root->r , mid + 1 , r , lo , hi);
  return a + b;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<pair<int,int>> br(N);
  unordered_map<int,int> vals;
  for(int i = 0 ; i < N ; ++i) {
    cin >> ar[i];
    br[i] = {ar[i] , i};
  }
  int start = 1;
  sort(br.begin(), br.end());
  for(int i = 0 ; i < N ; ++i) {
    if(i && br[i].first == br[i - 1].first) {
      ar[br[i].second] = start;
    } else {
      vals[start] = ar[br[i].second];
      ar[br[i].second] = start++;
    }
  }
  versions[0] = new Node();
  build(versions[0] , 1 , N);
  for(int i = 0 ; i < N ; ++i) {
    versions[i + 1] = new Node();
    update(versions[i], versions[i + 1], 1, N, ar[i] , 1);
  }
  vals[0] = 0;
  vals[start] = (int)(1e9 + 1);
  int ans = 0;
  int Q , i , j , k;
  cin >> Q;
  while(Q--) {
    cin >> i >> j >> k;
    i ^= ans;
    j ^= ans;
    k ^= ans;
    int lo = 0 , hi = start , res = -1;
    while(lo <= hi) {
      int mid = (lo + hi) >> 1;
      if(vals[mid] <= k) {
        res = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    assert(res != -1);
    if(i < 1) i = 1;
    if(j > N) j = N;
    if(i > j) {
      ans = 0;
      cout << 0 << '\n';
      continue;
    }
    ans = query(versions[j], 1, N, res + 1, N) - query(versions[i - 1], 1, N , res + 1, N);
    cout << ans << '\n';
  }
  return 0;
}
