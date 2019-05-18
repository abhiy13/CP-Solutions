#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int nax = 3010; 

int dp[nax][nax];

int n, m;
string foo, bar;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt; cin >> tt;
  while(tt--) {
    cin >> foo >> bar;
    n = (int) foo.size();
    m = (int) bar.size();
    for(int i = 0; i <= n; ++i) {
      for(int j = 0; j <= m; ++j) {
        if(i == 0) dp[i][j] = j;
        else if(j == 0) dp[i][j] = i;
        else if(foo[i - 1] == bar[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
        }
      }
    }
    cout << dp[n][m] << '\n';
  }  
  return 0;
}
