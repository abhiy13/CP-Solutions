//abhiy13
#include <bits/stdc++.h>
  using namespace std;

typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
#ifdef ABHI
  freopen("input.txt" , "r" , stdin);
#endif
  int T;
  cin>>T;
  while(T--){
    string s;
    cin >> s;
    vector < string > suffix;
    string pr;
    for(int i = (int) s.length() - 1 ; i >= 0 ; i--){
      pr += s[i];
      suffix.push_back(pr);
    }
    sort(suffix.begin(), suffix.end());
    for(int i = 0 ; i < N ; i++){
      
    }
  }
#ifdef ABHI
  cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
#endif
  return 0;
}
