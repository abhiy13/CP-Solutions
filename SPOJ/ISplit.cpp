//abhiy13
#include <bits/stdc++.h>
  using namespace std;
typedef long long ll;

string to_string(string s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef ABHI
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif


int main(){
  ios::sync_with_stdio(false);
#ifdef ABHI
  freopen("input.txt" , "r" , stdin);
  
#endif
  int T;
  cin>>T;
  while(T--){
    ll N;
    cin >> N;
    if(N&1){
      cout << 1 << ' ';
      N--;
    }  
    while(N >= 2){
      cout << 2 << ' ';
      N -= 2;
    }
  }
#ifdef ABHI
  cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
#endif
  return 0;
}
