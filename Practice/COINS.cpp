#include "bits/stdc++.h"
	using namespace std;
	
typedef long long ll;	
const int maxn = 1000000002;
 
int main(){
	ll dp[maxn];
	for(ll i = 0 ; i <= maxn ; i++){
		dp[i] = max(i,dp[i/2]+dp[i/3]+dp[i/4]);
	}	
	ll n;
	while(scanf("%lld" , &n)==1){
		printf("%lld\n" , dp[n]);
	}
	return 0;
} 
