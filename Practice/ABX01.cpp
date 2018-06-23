//partial
#include "bits/stdc++.h"
	using namespace std;
 
typedef long long ll;
 
int mE(ll x,ll n,int M=9)
{
    ll result=1;
    x%=9;
    while(n>0)
    {
        if(n&1){
            result*=x;
            result%=M;
        }
        x*=x;
        x%=M;
        n>>=1;
    }
    return result;
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
    	ll n , p;
    	cin>>n>>p;
    	ll ans = mE(n,p);
    	if(ans==0) cout<<9<<endl;
    	else cout<<ans<<endl;
    }
	return 0;
} 
