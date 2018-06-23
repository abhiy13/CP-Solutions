#include "bits/stdc++.h"
	using namespace std;
 
typedef long long ll;
 
const int MOD = 1e9+7;
 
#define N 1010
 
inline ll mul(ll n , ll k){
	n %=MOD , k %= MOD;
	return (n*k)%MOD;
}
 
inline ll add(ll a , ll b){
	a %= MOD , b %= MOD;
	return (a+b)%MOD;
}
 
ll power(ll n , ll p){
	ll ans = 1;
	n %= MOD;
	for(;p;p>>=1){
		if(p&1){
			ans = (ans*n)%MOD;
		}
		n = (n*n)%MOD;
	}
	return ans;
}
 
inline ll mmi(ll n){
	return power(n,MOD-2)%MOD;
}
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	ll fact[N];
	fact[0] = 1;
	for(int i = 1 ; i <= N ; i++){
		fact[i] = mul(fact[i-1],i);
	}
	int T;
	cin>>T;
	while(T--){
		ll n , t;
		cin>>n>>t;
		ll sum = 0;
		ll res = fact[t];
		for(int i = 1 ; i <= n ; i++){
	//		res = mul(res,mmi(i));
		res /= i;
			res = mul(res,i+t);
	//		cout<<res<<" \n";
			sum = add(sum,res);
		}	
		cout<<sum<<endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
