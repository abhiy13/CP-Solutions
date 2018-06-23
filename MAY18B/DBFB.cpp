#include "bits/stdc++.h"
	using namespace std;
 
 
#define PB(x) push_back(x)
#define EB(x) emplace_back(x)
#define F first
#define S second
#define FOR(i,n) for(ll i = 0 ; i < n ; i++)
#define FORR(i,a,b) for(ll i = (ll)a ; i < (ll)b ; i++)
#define RFOR(i,a,b) for(ll i = (ll)a ; i > (ll)b ; i--)
#define ll long long
#define llu unsigned long long
#define pii pair <int,int>
#define pll pair <int,int> 
#define vi vector <int>
 
#define MOD 1000000007
#define MAX 100000
//const int MOD = 1e9+7;
//Code for fibonacci in O(logN) time from GeeksForGeeks
 
void multiply(ll F[2][2], ll M[2][2]); 
void power(ll F[2][2], ll n);
ll aman;
 
ll fib(ll n , ll a , ll b){
  ll F[2][2] = {{1,1},{1,0}};
  if (n < 0)
    return 0;
  aman = 1;
  if(n==0) return a%MOD;
  if(n==1) return b%MOD;
//  if(n==2) return (a+b)%MOD; 
  power(F, n-1);
  aman = (F[0][1])%MOD;
//  cout<<aman<<endl;
  return (b*F[0][0])%MOD;
}
 
void power(ll F[2][2], ll n){
  if( n <= 0 || n == 1)
      return;
  ll M[2][2] = {{1,1},{1,0}};
  power(F, n/2);
  multiply(F, F);
  if (n%2 != 0)
     multiply(F, M);
}
 
void multiply(ll F[2][2], ll M[2][2]){
  ll x =  ((F[0][0]%MOD*M[0][0]%MOD)%MOD + (F[0][1]*M[1][0]))%MOD;
  ll y =  ((F[0][0]*M[0][1])%MOD + ((F[0][1]%MOD)*(M[1][1])%MOD))%MOD;
  ll z =  ((F[1][0]*M[0][0])%MOD + (F[1][1]*M[1][0])%MOD)%MOD;
  ll w =  ((F[1][0]*M[0][1])%MOD + (F[1][1]*M[1][1])%MOD)%MOD;
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
 
ll fib2(ll n , ll a , ll b){
  ll F[2][2] = {{1,1},{1,0}};
  if (n < 0)
    return 0;
  if(n==0) return a%MOD;
  if(n==1) return b%MOD;
  if(n==2) return (a+b)%MOD; 
  power(F, n-1);
  return (b*F[0][0])%MOD + a*(F[0][1])%MOD;
}
 
void solve(ll n,ll m){
	ll ar[m] , br[m];
	ll res = 0;
		FOR(i,m) cin>>ar[i];
		FOR(i,m) cin>>br[i];
		FOR(i,m){ FOR(j,m){
			res += fib2(n-1,ar[i],br[j]);
			res%=MOD;
		//	cout<<n<<" "<<ar[i]<<" "<<br[i]<<" "<<fib(n-1,ar[i],br[j])<<endl;
		}
	}
	cout<<res<<endl;
}
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int T;
	cin>>T;
	while(T--){
		ll n , m ;
		cin>>m>>n;
		aman = 0;
		if(n <= 100) {solve(n,m);continue;}
		llu ar[m] , br[m];
		FOR(i,m) {cin>>ar[i];}
		FOR(i,m) {cin>>br[i];}
		ll res = 0 , rees = 0;
		FOR(i,m){
			ll kp = fib(n-1,0,br[i]);
		//	cout<<kp<<endl;
			res += kp%MOD;
		//	cout<<n<<" "<<ar[i]<<" "<<br[i]<<" "<<fib(n-1,ar[i],br[j])<<endl;
		}
		FOR(i,m){
			rees += (((((m%MOD)*(aman%MOD))%MOD)*(ar[i])%MOD)%MOD + res%MOD)%MOD;
			rees %= MOD;
		//	cout<<rees<<" ";
		}
		cout<<rees<<endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
}
 
