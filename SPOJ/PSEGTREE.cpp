//abhiy13
#include <bits/stdc++.h>
  using namespace std;
const int N = 100001;

struct Node {
  int x;
  Node* l, *r;
  Node(Node* _l = NULL , Node* _r = NULL , int _x = 0) {
    l = _l;
    r = _r;
    x = _x;
  }
};

int ar[N];
Node* versions[N];

void build(Node* tree , int l , int r) {
  if(r < l) return;
  if(l == r) {
    tree->x = ar[l];
    return;
  }
  int mid = (l + r) >> 1;
  tree->l = new Node();
  tree->r = new Node();
  build(tree->l , l , mid);
  build(tree->r , mid + 1 , r);
  tree->x = tree->l->x + tree->r->x;
}

//~ void update(Node* old, Node* curr, int l , int r , int idx , int val) {
  //~ if(idx < l || idx > r || r < l) return;
  //~ if(l == r) {
    //~ curr->x = val;
    //~ return;
  //~ }
  //~ int mid = (l + r) >> 1;
  //~ if(idx <= mid) {
    //~ curr->r = old->r;
    //~ curr->l = new Node();
    //~ update(old->l , curr->l , l , mid , idx , val);
  //~ } else {
    //~ curr->l = old->l;
    //~ curr->r = new Node();
    //~ update(old->r , curr->r , mid + 1 , r , idx , val);
  //~ }
  //~ curr->x = curr->l->x + curr->r->x;
//~ }

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


// |----------------|---<--|----->--|

int query(Node* root , int l , int r , int lo , int hi) {
  if(lo > r || hi < l || r < l) return 0;
  if(root == NULL) assert(false);
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
  int n;
  cin >> n;
  for(int i = 0 ; i < n ; ++i) {
    cin >> ar[i];
  }
  versions[0] = new Node();
  build(versions[0] , 0 , n - 1);
  int Q;
  cin >> Q;
  int verno = 1;
  while(Q--) {
    int a , b , c , d;
    cin >> a >> b >> c >> d;
    if(a == 2) {
      cout << query(versions[b] , 0 , n - 1, c - 1 , d - 1) << '\n';
    } else {
      versions[verno] = new Node();
      update(versions[b] , versions[verno] , 0 , n - 1 , c - 1 , d);
      verno++;
    }
  }
  return 0;
}
