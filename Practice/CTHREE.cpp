#include "bits/stdc++.h"
	using namespace std;
 
#define ll long long
 
int main(){
	int t;
	cin>>t;
	while(t--){
		ll n , a , b , c;
		cin>>n>>a>>b>>c;
		vector <ll> d;
		for(ll i = 1 ; i*i <= n ; i++){
			if(n%i==0){
				d.push_back(i);
				if(i*i < n) d.push_back(n/i);
			}
		}
		sort(d.begin(), d.end());
		ll kk = (ll)d.size();
		ll ans = 0;
		for(ll i = 0 ; i < kk ; i++){
			if(d[i]>a) continue;
			for(ll j = 0 ; j < kk ; j++){
				if(n/d[i] %d[j] != 0 || d[j] > b) continue;
				ll z = n/d[i]/d[j];
				if(z>c) continue;
				ans++;  
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
