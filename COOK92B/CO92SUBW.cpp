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
#define vclr(x,y) memset(x,y,sizeof(x))
#define rsort(x) sort(x.rbegin(),x.rend())
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
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
 
 
const int N = 10000000;
const int NN = 1000000000;
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	ll ar[N];
	ar[0]=0;
	for(ll i=1;i<NN;i++){
		ar[i]=ar[i-1]+i;
		if(ar[i]>NN) break;
	}
	int t;
	cin>>t;
	FOR(tt,t){
		ll x;
		cin>>x;
		ll in;
		for(ll i=0;i<N;i++){
			if(ar[i]>x){
				in=i;
				break;
			}
		}
		ll ans = in+(ar[in]-x);
 		ll res = (in-1) + (x-ar[in-1]);
 		cout<<min(ans,res)<<endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
