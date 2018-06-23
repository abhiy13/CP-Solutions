#include "bits/stdc++.h"
	using namespace std;
 
 
typedef long long ll;
 
int main(){
	int t;
	cin>>t;
	while(t--){
		ll a , b , c;
		cin>>a>>b>>c;
		ll ar[a];
		for(ll i = 0 ; i < a ; i++) {
			cin>>ar[i];
		}
		sort(ar,ar+a);
		ll ok = ar[0] ,ans = 0;
		for(ll i = 1 ; i < a ; i++){
			if(ar[i] >= (b*ok + c)){
				ans++;
				ok = ar[i];
			}
		}
		cout<<ans+1<<endl;
	}
	return 0;
} 
