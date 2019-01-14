//abhiy13
#include <bits/stdc++.h>

using namespace std;


string to_string(string s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef ABHI
  #define line_debug(x) cerr << "[" << __LINE__ << "]: " << #x << "->" << to_string(x) << '\n';
  #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
  #define line_debug(x) 42
  #define debug(...) 42
#endif


struct Node {
  int x;
  Node* l, *r;
  Node(Node* _l = NULL , Node* _r = NULL , int _x = 0) {
    l = _l;
    r = _r;
    x = _x;
  }
};

const int M = (1e5 + 10);
Node* versions[M];

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
   curr->x = val + old->x;
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

int query(Node *a, Node *b, int l, int r, int k) {
  if(l == r) {
    return l;
  }
  int mid = (l + r) >> 1;
  assert(a->l != NULL && b->l != NULL);
  int ct = a->l->x - b->l->x;
  if(ct >= k) {
    return query(a->l, b->l, l, mid, k);
  }
  return query(a->r, b->r, mid + 1, r, k - ct);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, Q;
  cin >> N >> Q;
  vector<pair<int, int>> br(N);
  vector<int> ar(N);
  for(int i = 0; i < N; ++i) {
    cin >> br[i].first;
    br[i].second = i;
  }
  sort(br.begin(), br.end());
  unordered_map<int, int> vals;
  vector<int> inv(M);
  int cnt = 0;
  for(int i = 0; i < N; ++i) {
    if(vals.find(br[i].first) == vals.end()) {
      vals[br[i].first] = cnt;
      inv[cnt] = br[i].first;
      ar[br[i].second] = cnt++;
    } else {
      ar[br[i].second] = vals[br[i].first];
    }
  }
  debug(ar, br);
  versions[0] = new Node();
  build(versions[0], 0, M);
  for(int i = 0; i < N; ++i) {
    versions[i + 1] = new Node();
    update(versions[i], versions[i + 1], 0, M, ar[i], 1);
  }
  int l, r, k;
  while(Q--) {
    cin >> l >> r >> k;
    debug(l, r, k);
    cout << inv[query(versions[r], versions[l - 1], 0, M, k)] << '\n';
  }
  return 0;
}
