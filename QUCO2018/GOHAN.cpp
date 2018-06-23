#include <bits/stdc++.h>
	using namespace std;
 
using ll = long long;
 
int main() {
  	ll t;
	cin>>t;
	while(t--){
		ll r,l,c,v;
		cin>>r>>l>>c>>v;
		printf("%.9lf",1-r*r*1.0*c/(4*l));
		cout<<'\n';
	}
	return 0;
} 
