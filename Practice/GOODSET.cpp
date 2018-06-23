#include <bits/stdc++.h>
	using namespace std;
 
#define io ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
int main(){
	io;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==1) {cout<<"1\n";continue;}
		if(n==2) {cout<<"1 2\n";continue;}
		int j = 3;
		for(int i = 0 ; i < n ; i++){
			cout<<j<<" ";
			j+=2;		
		}
		cout<<"\n";
	}
	return 0;
} 
