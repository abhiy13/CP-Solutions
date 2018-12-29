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
  cin >> T;
  for(int tt = 1  ; tt <= T ; tt++){
    int N , M;
    cin >> N >> M;
    vector < vector < int > > V(N , vector <int>());
    for(int i = 0 ; i < M ; i++){
      int x , y;
      cin >> x >> y;
      x--,y--;
      V[x].push_back(y);
      V[y].push_back(x);
    }
    vector < int > side(N , -1);
    function <bool()> is_bipartite = [&](){
      queue<int> q;  
      bool ok = true;
      for (int st = 0; st < N ; ++st) {
        if (side[st] == -1) {
          q.push(st);
          side[st] = 0;
          while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto u : V[v]) {
              if (side[u] == -1) {
                side[u] = side[v] ^ 1;
                q.push(u);
              } else {
                ok &= (side[u] != side[v]);
              }
            }
          }
        }  
      }
      return ok;
    };
    cout << "Scenario #" << tt <<":\n";
    cout << (!is_bipartite() ? "Suspicious bugs found!" : "No suspicious bugs found!") << '\n'; 
  }
#ifdef ABHI
  cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
#endif
  return 0;
}
