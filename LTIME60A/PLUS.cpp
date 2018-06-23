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
 
const ll inf = 100000000000000000;
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int T;
	cin>>T;
	while(T--){
		ll n ,m;
        cin>>n>>m;
        ll ar[n][m] = {0} , res = -inf;
        FOR(i,n) FOR(j,m) cin>>ar[i][j];
        FORR(i,1,n-1){
        	FORR(j,1,m-1){
        		ll l=ar[i][j-1],r=ar[i][j+1],f=ar[i-1][j],b=ar[i+1][j],temp = 0;
        		temp = r;
        		FORR(k,j+2,m){
        			temp += ar[i][k];
        			if(temp > r) r = temp;
        		}
        		temp = l;
        		RFOR(k,j-2,-1){
        			temp += ar[i][k];
        			if(temp > l) l = temp;
        		}
        		temp = b;
        		FORR(k,i+2,n){
        			temp += ar[k][j];
        			if(temp > b) b = temp;
        		}
        		temp = f;
        		RFOR(k,i-2,-1){
        			temp += ar[k][j];
        			if(temp > f) f = temp;
        		}
        		ll ans = l+r+f+b+ar[i][j];
        		res = max(res,ans);
        	}
     	}
    	cout<<res<<endl;
    }
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
}
 
