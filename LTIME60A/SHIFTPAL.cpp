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
#define pll pair <ll,ll> 
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int T;
	cin>>T;
	while(T--){
		string s , k;
		cin>>s;
		k = s;
		ll res = 0;
		FOR(i,(ll)s.size()){
			k += s[i];
			bool ok = true;
			ll n = k.size();
			for(int j = i ; j < n/2 + i ; j++){
				if(k[j] != k[n-j-1]) {ok = false; break;}
			} 
			if(ok) res++;
		}
		cout<<res<<endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
}
 
