/****************************************************
*****************************************************
**               Abhishek(abhiy13)                 **          
**             Chandigarh University               **
**   https://www.youtube.com/watch?v=r6zIGXun57U   **
*****************************************************
****************************************************/ 
 
 
#include "bits/stdc++.h"
	using namespace std;
 
 
//`````````````````````````````````````````````````````Random Stuff Here```````````````````````````````````````````````````````//
	
#define io std::ios::sync_with_stdio(false);
#define FOR(i,n) for(ll i = 0 ; i < n ; i++)
#define FORR(i,a,b) for(ll i = a ; i < b ; i++)
#define RFOR(i,a,b) for(ll i = a ; i > b ; i--)	
#define all(x) begin(x),end(x)
#define SZ(x) x.size()
#define ll long long
#define llu unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define mp(a,b) make_pair(a,b)
#define clr(x) memset(x,0,sizeof(x))
#define ms(x,y) memset(x,y,sizeof(x))
#define rsort(x) sort(x.rbegin(),x.rend())
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define sll(x) scanf("%lld" , &x);
#define prll(x) printf("%lld\n",x);
 
#define TRACE
 
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif   
 
 
//``````````````````````````````````````````````````````Start of Program`````````````````````````````````````````````````//
 
int main(){
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	ll t;
	sll(t);
	while(t--){
		ll n;sll(n);
		ll ar[n];
		ll sum = 0;
		FOR(i,n) {
			sll(ar[i]);
			sum+=ar[i];
		}
		vector<int> ans;
		ans.pb(1);
		for(ll k = 2 ; k <= n ; k++){
			if(sum%k != 0){
				ans.pb(0);
			}else{
				ll reqsum = sum/k;
				ll ts = 0;
				ll kk = 0;
				bool ok = true;
				for(ll i = 0 ; i < n ; i++){
					if(ar[i]+ts>reqsum){
						ok = false;
						break;
					}else{
						if(ar[i]+ts==reqsum){
							ts = 0;
							kk++;			
						}else{
							ts += ar[i];
						}
					}
				}
				if(!ok || kk != k) ans.pb(0);
				else ans.pb(1);
			}
		}
		FOR(i,(ll)ans.size()) cout<<ans[i];
		cout<<endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
