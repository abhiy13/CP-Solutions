#include "bits/stdc++.h"
	using namespace std;
	
int main(){
	int t;
	cin>>t;
	for(int tt=1 ; tt <= t ; tt++){
		cout<<"Case "<<tt<<": ";
		int a,b;
		cin>>a>>b;
		long long ans  = a-b+1;
		if(ans>=0){
			cout<<(ans*(ans+1))/2<<endl;
		}else{
			cout<<0<<endl;
		}
	} 
	return 0;
}  
