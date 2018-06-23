/****************************************************
*****************************************************
**		     Abhishek(abhiy13)		           **          
**  		  Chandigarh University                  **
** 	 https://www.youtube.com/watch?v=r6zIGXun57U  **
*****************************************************
*****************************************************/ 
 
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
#define F first
#define S second
#define TRACE
#define mod 1000000007
 
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
 
const int N = 1e5+10;
 
llu ans[N];
llu pr[N];
 
void pre(){
     ans[0] = 0;
     pr[0] = 0;
     for(ll i = 1 ; i <= N ; i++){
          ans[i] = (i*i)  - (i-1)*(i-1);
          pr[i] += ans[i]*ans[i] + pr[i-1];
     }
     
}
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	pre();
	int t;
	cin>>t;
	FOR(tt,t){
          llu l , r;
          cin>>l>>r;
          cout<<(pr[r] - pr[l])%mod<<endl;
	}    
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
