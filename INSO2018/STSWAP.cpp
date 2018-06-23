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
#define ff first
#define ss second
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
 
ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	ll n,k;cin>>n>>k;
    ll a[n];
	FOR(i,n) cin>>a[i];
    if(k<(n/2)){  
    	sort(a,a+n);
        FOR(i,n)cout<<a[i]<<" ";
	}else if(k>=n/2&&k<=n-2){
	    ll b[2*(n-k-1)]; 
		for(int i=0;i<n-k-1;i++)
		    b[i]=a[i];
		    for(int i=n-k-1;i<(2*(n-k-1));i++)
		        b[i]=a[i+2*(k+1)-n]; 
 			sort(b,b+2*(n-k-1));
			for(int i=0;i<n-k-1;i++)
				a[i]=b[i];
			for(int i=k+1;i<n;i++)
			    a[i]=b[i-(2*(k+1)-n)]; 
 		    FOR(i,n) cout<<a[i]<<" ";
    }else if(k>n-2){    
    	FOR(i,n)
    	 cout<<a[i]<<" ";									  
    }					
    cout<<endl;
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
