//abhiy13
#include <bits/stdc++.h>
  using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  cin >> tt;
  while(tt--){
    int N , K;
    cin >> N >> K;
    long long sum = 0;
    vector<long long> ar(N);
    for(int i = 0 ; i < N ; ++i) {
      cin >> ar[i];
      sum += ar[i];
    }
    //~ if(K == 1) {
      //~ for(int i = 0 ; i < N ; ++i) {
        //~ cout << ar[i];
        //~ if(i < N - 1) cout << " / ";
        //~ else cout << "\n";
      //~ }
      //~ continue;
    //~ }
    long long lo = *min_element(ar.begin() , ar.end()) , hi = sum , res = -1;
    function<bool(long long)> check = [&](long long x) {
      int req = 0;
      long long rs = 0;
      for(long long y : ar) {
        if(y > x) return false;
        if(y + rs > x) {
          req++;
          rs = y;
        } else {
          rs += y;
        }
      }
      return req + 1 <= K;
    };
    while(lo <= hi) {
      long long mid = (lo + hi) >> 1;
      if(check(mid)) {
        hi = mid - 1;
        res = mid;
      } else {
        lo = mid + 1;
      }
    }
    //~ vector<string> s;
    assert(res != -1);
    long long rs = 0;
    vector<int> reas;
    int cnt = 1;
    for(int i = N - 1 ; i >= 0 ; --i) {
      if(rs + ar[i] > res || K - cnt - 1 == i) {
        reas.push_back(-1);
        rs = ar[i];
        reas.push_back(i);
        cnt++;
      } else {
        reas.push_back(i);
        rs += ar[i];
      }
    }
    reverse(reas.begin() , reas.end());
    for(auto x : reas) {
      cout << (x == -1 ? "/" : to_string(ar[x])) << ' ';
    }
    cout << '\n'; 
  }
  return 0;
}
