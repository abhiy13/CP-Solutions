#include "bits/stdc++.h"
	using namespace std;
 
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		if(n==1){
			cout<<1<<endl;
		}else{
			int mid = n/2;
			for(int i = 0 ; i < n ; i++){
				cout<<mid++<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}	 
