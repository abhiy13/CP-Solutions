//abhiy13
#include <bits/stdc++.h>
  using namespace std;

class fenwick {
  vector<int> fenw;
  int N;
public: 
  fenwick(int _N) : N(_N) {
    fenw.resize(N);
  }
  void modify(int idx , int val) {
    while(idx < N) {
      fenw[idx] += val;
      idx |= (idx + 1);
    }
  }
  int get(int idx) {
    int sum = 0;
    while(idx >= 0) {
      sum += fenw[idx];
      idx = (idx & (idx + 1)) - 1;
    }
    return sum;
  }
};

struct query {
  int l , r , idx; 
  long long k;
  query(int _l = 0 , int _r = 0 , long long _k = 0 , int _idx = 0) : l(_l) , r(_r) , k(_k) , idx(_idx) {};
  bool operator < (const query &q) const {
    return k < q.k;
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  int cnt = 0;
  fenwick fenw(N);
  vector< pair<long long,int> > ar(N);
  for(auto &x : ar) {
    cin >> x.first;
    x.second = cnt++;
  } 
  sort(ar.begin() , ar.end());
  int Q;
  cin >> Q;
  vector<query> q(Q);
  cnt = 0;
  vector<int> ans(Q);
  for(auto &x : q) {
    cin >> x.l >> x.r >> x.k;
    x.l-- , x.r--;
    x.idx = cnt++;
  }
  sort(q.begin() , q.end());
  int j = Q - 1 , i = N - 1;
  while(j >= 0) {
    while(i >= 0 && ar[i].first > q[j].k) {
      fenw.modify(ar[i].second , 1);
      i--;
    }
    auto x = q[j];
    ans[x.idx] = fenw.get(x.r) - fenw.get(x.l - 1);
    j--;
  }
  for(auto x : ans) {
    cout << x << '\n';
  }
  return 0;
}
