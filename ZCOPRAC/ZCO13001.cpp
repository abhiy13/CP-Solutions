#include "bits/stdc++.h"
	using namespace std;
 
typedef long long ll;
 
int main(){
	int n;
	cin>>n;
	int ar[n];
	for(int i = 0 ; i < n ; i++){ 
		cin>>ar[i];
	}
	sort(ar,ar+n);
	ll sum = 0 , ans = 0;
	for(int i = 0 ; i < n ; i++){
		sum += ar[i];
		ans += abs(ar[i]*(i+1) - sum);
	}
	cout<<ans;
	return 0;
} 
