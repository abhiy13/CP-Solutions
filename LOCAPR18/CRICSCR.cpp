#include "bits/stdc++.h"
	using namespace std;
 
#define PB(x) push_back(x)
#define EB(x) emplace_back(x)
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
 
typedef long long ll;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;
typedef vector <int> vi;
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	ll n;
	cin>>n;
	vector<pll> ar(n,{0,0});
	for(int i = 0 ;i < n ; i++){
		cin>>ar[i].F>>ar[i].S;
	}
	for(int i = 1 ; i < n ; i++){
		bool ok = true;
		if(ar[i].F < ar[i-1].F) ok = false;
		if(ar[i].S < ar[i-1].S) ok = false;
		if(ar[i].S > 10) ok = false;
		if(ar[i-1].S == 10){
			if(ar[i-1].F != ar[i].F) ok = false;
		}
		if(!ok){
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
