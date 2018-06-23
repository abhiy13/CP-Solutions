#include "bits/stdc++.h"
  using namespace std;
 
typedef long long ll;
const int MOD = 1e9 + 7;
 
void multiply(ll a[2][2], ll b[2][2]){
    int ans[2][2];
    for(int i = 0 ; i < 2 ; i++) for(int j = 0 ; j < 2 ; j++){
        ans[i][j]=0;
        for(int k = 0 ; k < 2 ; k++) ans[i][j] = (ans[i][j]+(a[i][k]*b[k][j])%MOD)%MOD;
    }
 
    for(int i = 0 ; i < 2 ; i++) for(int j = 0 ; j < 2 ; j++) a[i][j] = ans[i][j];
}
 
ll matrixpower(ll b , ll k){
    ll a[2][2];
    a[0][0] = k;
    a[0][1] = 1;
    a[1][0] = 1;
    a[1][1] = k;
    ll c[][2] = {{k,1},{1,k}};
    while(b){
        if(b&1) multiply(c,a);
        multiply(a,a);
        b>>=1;
    }
    ll answer = 2*c[0][0];
    answer %= MOD;
    return answer;
}
 
int main(){
  ios::sync_with_stdio(false);
  #ifdef ABHI
    freopen("input.txt" , "r" , stdin);
  #endif
  int T;
  cin >> T;
  while(T--){
    int n , k;
    cin >> n >> k;
    cout << matrixpower(n-1,k) << endl;
  }
  #ifdef ABHI
    cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
  #endif
  return 0;
} 
