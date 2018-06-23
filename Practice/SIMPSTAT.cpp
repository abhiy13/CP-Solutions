#include <bits/stdc++.h>
	using namespace std;
 
int main(){
	int t;
	cin>>t;
	while(t--){
		int n , k;
		cin>>n>>k;
		int ar[n];
		long sum = 0;
		for(int i = 0 ; i < n ; i++) {cin>>ar[i];sum+=ar[i];}
		sort(ar,ar+n);
		for(int i = 0 ; i < k ; i++){
			sum-=ar[i]+ar[n-i-1];
		}
		double ans = (double)sum/(double)(n-2*k);
		printf("%.9lf\n" , ans);
	}
	return 0;
} 
