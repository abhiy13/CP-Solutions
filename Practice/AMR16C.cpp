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
#define pll pair <int,int> 
#define vi vector <int>
 
#define N 1000010
 
ll primes[N];
 
void init(){
	memset(primes , true , sizeof primes);
	primes[0] = false;
	primes[1] = false;
	for(int i = 2 ; i*i < N ; i++){
		if(primes[i]){
			for(int j = 2*i ; j < N ; j += i){
				primes[j] = false;
			}
		}
	}
}
 
bool is(ll x){
	ll res = 2;
	if(x%2 == 0){
		res++;
	}
	for(int i = 3 ; i*i <= x ; i += 2){
		if(x%i == 0){
			res++;
			while(x%i == 0) x /= i;
		}
	}
	if((res&1) and primes[res]) return true;
	return false;
}
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	init();
	int T;
	cin>>T;
	while(T--){
		ll n ,supp = 0;
		cin>>n;
		ll ar[n];
		for(int i= 0 ; i < n ; i++){
			cin>>ar[i];
		}
		sort(ar,ar+n,greater<ll>());
		for(int i = 0 ; i < n ; i++){
			bool ok = false;
			ll x = sqrt(ar[i]);
			if(ar[i] != 1 and 1LL*x*x == ar[i]){
				ok = true;
			}
			if(ok){
				cout<<i+1<<endl;
			  supp++;
			}
		}
		if(supp == 0) cout<<"No supporter found.\n";
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
