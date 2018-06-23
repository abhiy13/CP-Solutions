#include <bits/stdc++.h>
  using namespace std;
  using ll = long long;
 
const int MOD = 1000000007;
 
inline ll add(ll a , ll b){
  return (a%MOD + b%MOD)%MOD; 
}
 
inline ll mul(ll a , ll b){
  return (a%MOD * b%MOD)%MOD;
}
 
int main(){
  ios::sync_with_stdio(false);
  #ifdef ABHI
    freopen("input.txt" , "r" , stdin);
  #endif
  int T;
  cin>>T;
  while(T--){
    ll a , b , c , res = 0;
    cin >> a >> b >> c;
    vector < ll > A(a) , B(b) , C(c) , prefixA(a+1 , 0) , prefixC(c+1 , 0);
    for(int i = 0 ; i < a ; i++) cin >> A[i];
    for(int i = 0 ; i < b ; i++) cin >> B[i];
    for(int i = 0 ; i < c ; i++) cin >> C[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    for(int i = 0 ; i < a ; i++) prefixA[i + 1] = add(prefixA[i] , A[i]);
    for(int i = 0 ; i < c ; i++) prefixC[i + 1] = add(prefixC[i] , C[i]);
    for(int i = 0 ; i < b ; i++){
      ll pos_a = upper_bound(A.begin(), A.end() , B[i]) - A.begin();
      ll pos_c = upper_bound(C.begin(), C.end() , B[i]) - C.begin();
      res += mul(add(prefixA[pos_a] , mul(pos_a,B[i])) , add(prefixC[pos_c] , mul(pos_c,B[i])));
      res %= MOD;
    }
    cout << res << '\n';
  }
  #ifdef ABHI
    cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
  #endif
  return 0;
}
 
