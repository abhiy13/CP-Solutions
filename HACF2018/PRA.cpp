#include "bits/stdc++.h"
	using namespace std;
 
#define		io				std::ios::sync_with_stdio(false);
#define		FOR(i,n)		for(int i = 0 ; i < n ; i++)
#define		rep(i,a,b)		for(int i = a ; i < b ; i++)
#define 	rrep(i,a,b)		for(int i = a ; i > b ; i--)
#define 	all(x)			x.begin(),x.end()
#define 	SZ(x)			x.size()
 
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
const int maxn = 1000000;
 
bool dp[maxn];
 
void precalc(){
    memset(dp,true, sizeof(dp));
    dp[1] = false;
    for (int p=2; p*p<=maxn+1; p++){
        if (dp[p] == true){
            for (int i=p*2; i<=maxn; i += p)
                dp[i] = false;
        }
    }
}
 
int main(){
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	precalc();
	int t , l ,r;
	cin>>t;
	while(t--){
		cin>>l>>r;
		ll ans = 0;
		rep(i,l,r+1){
			if(dp[i]) ans++;
		}
		printf("%.6lf\n" , (double)ans/(r-l+1));
	}
	#ifdef ABHI
		cerr<<"Time Elapsed " << (double)1000.00*clock()/CLOCKS_PER_SEC<<" ms\n";
	#endif
	return 0;
} 
