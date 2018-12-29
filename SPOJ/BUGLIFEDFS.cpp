//abhiy13
#include <bits/stdc++.h>
  using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for(int tt = 1 ; tt <= T ; tt++){
    int N , M;
    cin >> N >> M;
    vector < vector <int> > ar(N , vector < int >());
    for(int i = 0 ; i < M ; i++){
      int x , y;
      cin >> x >> y;
      x-- , y--;
      ar[x].push_back(y);
      ar[y].push_back(x);
    }
    vector < int > S(N , -1);
    bool ok = true;
    function <void(int , int)> dfs = [&](int curr , int par){
      if(S[curr] != -1) {
        ok &= (par != S[curr]);
        return;
      }
      S[curr] = par ^ 1;
      for(auto x : ar[curr]){
        dfs(x , par ^ 1);
      }
    };
    for(int i = 0 ; i < N ; i++) if(S[i] == -1) dfs(i , 0);
    cout << "Scenario #" << tt <<":\n";
    cout << (!ok ? "Suspicious bugs found!" : "No suspicious bugs found!") << '\n';
  }
  return 0;
}
