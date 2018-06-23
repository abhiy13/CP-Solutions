#include "bits/stdc++.h"
	using namespace std;
 
typedef long long ll;
 
ll iscis(ll x1, ll y1, ll x2, ll y2,ll r1, ll r2)
{
    ll d = (x1 - x2) * (x1 - x2) +(y1 - y2) * (y1 - y2);
    ll r = (r1 + r2) * (r1 + r2);
    if (d == r)
        return 1;
    else if (d > r)
        return -1;
    else 
    	return 0;
}
 
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll x1 , y1 , r1 , x2 , y2 , r2;
		cin>>x1>>y1>>r1>>x2>>y2>>r2;
		ll res = iscis(x1 , y1 , x2 , y2 , r1 , r2);
		if(res == 1) cout<<"tangential\n";
		else if(res==-1) cout<<"not overlapping\n";
		else  cout<<"overlapping\n";
	}	
	return 0;
} 
