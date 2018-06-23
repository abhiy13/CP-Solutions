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
 
ll n, h;
vector<ll> pp;
const int inf = 1e9;
 
bool pala(ll x){
    int hr=0;
    FOR(i,n){
        hr+=(pp[i]/x);
        if(pp[i]%x!=0) hr++;
    }
    if(hr>h) return false;
    return true;
}
 
int main() {
    io
    #ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n>>h;
        ll lol;
        FOR(i,n) {cin>>lol;pp.push_back(lol);};
        sort(all(pp));
        ll lolw=1, lolh=inf;
        while(lolw<lolh){
           ll lolm=(lolw+lolh)>>1;
           if(pala(lolm)) lolh=lolm;
           else lolw=lolm+1;
        }
        cout<<lolw<<endl;
        pp.clear();
    }
    #ifdef ABHI
		timer
	#endif
    return 0;
} 
