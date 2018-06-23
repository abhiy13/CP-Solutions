#include <bits/stdc++.h>
	using namespace std;
 
const int ms = 1e6;
 
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ar[ms];
		memset(ar,-1,sizeof(ar));
		for(int i = 0 ; i < n ; i++){
			int a;
			cin>>a;
			(ar[a]==-1)?ar[a]=1:ar[a]++;
		}
		for(int i = 0 ; i < ms+1 ; i++){
			if(ar[i]==-1) continue;
			if(ar[i]==1) {cout<<i<<"\n";break;}
		}
	}
	return 0;
} 
