#include "bits/stdc++.h"
	using namespace std;
 
typedef long long ll;
 
int main(){
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll sum = 0;
		for(int i = 7 ; i <= n ; i+=7){
			sum+=i;
		}
		cout<<sum<<endl;
	}	
	return 0;
} 
