/*
 *	Abhishek(abhiy13)
 *	MARCH18
 * 	https://www.youtube.com/watch?v=r6zIGXun57U
*/
 
#include "bits/stdc++.h"
	using namespace std;
 
#define	io				std::ios::sync_with_stdio(false);
#define	FOR(i,n)		for(ll i = 0 ; i < n ; i++)
#define	FORR(i,a,b)		for(ll i = a ; i < b ; i++)
#define RFOR(i,a,b)		for(ll i = a ; i > b ; i--)
#define timer			cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";	
#define all(x)			begin(x),end(x)
#define SZ(x) x.size()
 
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int N = 100000 + 10000 + 10000;
 
bool prime[N];
ll iss[N];
 
void init(){
	ll n = N;
	ll kk = 0;
	memset(prime, true, sizeof(prime)); 
    prime[1] = false;
    prime[0] = false;
    for (ll p=2; p*p<=n; p++){
        if (prime[p] == true){
            for (ll i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
    FORR(i,2,n){
    	if(prime[i]){ iss[kk++] = i; }
    }
}
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	init();
	int t;
	cin>>t;
	FOR(tt,t){
		ll n;
		cin>>n;
		ll i  = 0;
		while(iss[i]<=n){
			if(n%iss[i]==0) cout<<iss[i]<<" ";
			i++;
		}
		cout << endl;
	}
	#ifdef ABHI
		timer
	#endif
	return 0;
} 
