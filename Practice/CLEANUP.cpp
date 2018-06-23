#include <bits/stdc++.h>
	using namespace std;
#define io ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);	
#define endl "\n";
int main(){
	io;
	int t;
	cin>>t;
	while(t--){
		int n , k;
		cin>>n>>k;
		int ar[n];
		memset(ar,1,sizeof(ar));
		for(int i = 0 ; i < k ; i++){
			int p;
			cin>>p;
			ar[p-1]=0;
		}
		int l = 0; 
		for(int i = 0 ; i < n ; i++){
			if(ar[i]==0) continue;
			l++;              
			if(l%2==1){
				cout<<i+1<<" ";
				ar[i]=0;
			}
		}
		cout<<endl;
		for(int i=0 ; i < n ; i++){
			if(ar[i]!=0) cout<<i+1<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
