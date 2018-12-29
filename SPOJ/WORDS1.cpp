//abhiy13
#include <bits/stdc++.h>
  using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  cin >> tt;
  while(tt--){
    int N;
    cin >> N;
    vector<int> indeg(26) , outdeg(26);
    int s = 0 , e = 0;
    vector<vector<int>> G(26 , vector<int>(26 , 0));
    for(int i = 0 ; i < N ; ++i) {
      string x;
      cin >> x;
      indeg[x.back() - 'a']++;
      outdeg[x[0] - 'a']++;  
      G[x.back() - 'a'][x[0] - 'a']++;
      G[x[0] - 'a'][x.back() - 'a']++;
    }
    int z = 0;
    while(z <= 25) {
      int i = z;
      if(indeg[i] == outdeg[i] + 1) {
        s++;
      } else if(indeg[i] + 1 == outdeg[i]) {
        e++;
      } else if(indeg[i] != outdeg[i]) {
        break;
      }
      z++;
    }
    connected = true;a 
    bool ok = (s == 1 && e == 1);
    cout << ((z == 26 && ok && connected) ? "Ordering is possible." : "The door cannot be opened.") << '\n';
  }
  return 0;
}
