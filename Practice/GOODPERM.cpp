#include <bits/stdc++.h>
  using namespace std;
 
int main(){
  ios::sync_with_stdio(false);
  #ifdef ABHI
    freopen("input.txt" , "r" , stdin);
  #endif
  int T;
  cin >> T;
  while(T--){
    int N , K;
    cin >> N >> K;  
    vector < int > ar(N);
    vector < int > gen(N);
    iota(gen.begin(), gen.end(),1);
    for(int i = 0 ; i < N ; i++){
      cin >> ar[i];
    }
    function<bool(vector < int >)> ok = [&](vector < int > S){
      for(int i = 0 ; i < (int) ar.size() ; i++){
        if(ar[i] != 0){
          if(ar[i] != S[i]) return false;
        }
      }
      return true;
    };
    function <bool(vector < int >)> OK = [&](vector < int > S){
      int res = 0;
      for(int i = 1 ; i < (int) ar.size() ; i++){
        if(S[i] > S[i-1]) res++;
      }
      return res == K;
    };
    int ans = 0;
    do{
      if(ok(gen)){
        ans += OK(gen) ? 1 : 0;
      }
    }while(next_permutation(gen.begin(), gen.end()));
    cout << ans << endl;
  }
  #ifdef ABHI
    cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
  #endif
  return 0;
}
 
