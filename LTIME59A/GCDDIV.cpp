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
typedef vector <int> vi;
 
ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 
ll lcm(ll a , ll b){
	return((a*b)/gcd(a,b));
}
 
 
 
bool issolvable(ll n , ll k){
    while (n%2 == 0){
        n = n/2;
        if(k < 2){
        	return false;
        }
    }
    for (int i = 3; i <= sqrt(n); i = i+2){ 
        while (n%i == 0){
            n = n/i;
            if(k < i){
        		return false;
			}
        }
    }
    if (n > 2){
		if(k < n)
			return false;
    }
    return true;
}
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int T;
	cin>>T;
	while(T--){
		ll n , k;
		cin>>n>>k;
		ll ar[n];
		ll ggc = 0;
		for(int i = 0; i < n ; i++) {
			cin>>ar[i];
			if(i==0) ggc = ar[i];
			else{
				ggc = gcd(ar[i],ggc);
			}
		}
		if(issolvable(ggc,k)) cout<<"YES\n";
		else cout<<"NO\n";
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
