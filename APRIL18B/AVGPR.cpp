#include "bits/stdc++.h"
	using namespace std;
 
#define io std::ios::sync_with_stdio(false);
#define FOR(i,n) for(ll i = 0 ; i < n ; i++)
#define FORR(i,a,b) for(ll i = a ; i < b ; i++)
#define RFOR(i,a,b) for(ll i = a ; i > b ; i--)	
#define ll long long
#define llu unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second  
#define slld(x) scanf("%lld" , &x)
#define sii(x) scanf("%d" , &x)
#define sdoub(x) scanf("%lf" , &x)
 
const int N = 1e3 + 10;
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
  int t;
  cin >> t;
  while(t--){
    int n, x; cin >> n;
    unordered_map<ll, ll> check;
    FORR(i,-1000,1001) check[i] = 0;
    for (int i = 0; i < n; ++i) {
      cin >> x;
      check[x]++;
    }
    ll ans = 0;
    for (int i = -1000; i <= 1000; ++i) {
       if(check[i] == 0) continue;
       if(check[i] > 1) {
        ans += (check[i]*(check[i]-1))/2;
       } 
       for (int j = i+1;  j <= 1000; ++j) {
        if((check[j] == 0) or ((abs(i+j))%2 == 1)) continue;
        if(check[(i + j)/2]) {
           ans += check[i]*check[j];
           //cout<<i<<" "<<j<<endl;
        }
       }
    }
    cout << ans << endl;
  }
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
}  
