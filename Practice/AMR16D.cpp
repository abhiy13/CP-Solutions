#include <bits/stdc++.h>	
	using namespace std;
 
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		if(k<3) {cout<<"yes\n";continue;}
		if(k%3==0 && (n-k)>=3) {cout<<"no\n";continue;}
		cout<<"yes\n";
	}
	return 0;
}
 
