#include "bits/stdc++.h"
  using namespace std;
 
bool ok(char c){
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
 
int main(){
  ios::sync_with_stdio(false);
  #ifdef ABHI
    freopen("input.txt" , "r" , stdin);
  #endif
  string s;
  cin >> s;
  vector < int > ar((int)s.size() , 1);
  if(s[0] == '*') {
    s[0] = 'c';
    ar[0] = 21;
  }else{
    ar[0] = 1;
  }
  int ans = ar[0];
  for(int i = 1 ; i < (int) s.size() ; i++){
    if(s[i] == '*'){
      if(!ok(s[i-1])){
        ar[i] = 5;
        s[i] = 'a';
      }else{
        ar[i] = 21;
        s[i] = 'c';
      }
    }else{
      ar[i] = 1;
    }
    ans *= ar[i];
  }
  cout << ans << endl;
  #ifdef ABHI
    cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
  #endif
  return 0;
} 
