//abhiy13
#include <bits/stdc++.h>
  using namespace std;
const int MAXN = 100005;
template <typename T>
class fenwick {
  public:
  vector<T> fenw;
  long long n;
 
  fenwick(long long _n) : n(_n) {
    fenw.resize(n);
  }
 
  void modify(long long x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
 
  T get(long long x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<long long> ar(N);
  for(int i = 0 ; i < N ; ++i) {
    cin >> ar[i];
  }
  long long res = 0;
  fenwick<long long> fenw(MAXN) , f(MAXN);
  for(int i = 0 ; i < N ; ++i) {
    long long p = fenw.get(MAXN - 1) - fenw.get(ar[i]);
    fenw.modify(ar[i] , 1);
    long long q = f.get(MAXN - 1) - f.get(ar[i]);
    f.modify(ar[i] , p);
    res += q;
  }
  cout << res << '\n';
  return 0;
}
