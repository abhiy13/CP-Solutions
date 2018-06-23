#include<bits/stdc++.h>
	using namespace std;
int main()
{       ios::sync_with_stdio(false);
	cin.tie(NULL);
        int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a=0;int count=0;int ar[100003]={0};
		for(int i=0;i<n;i++) {
				cin>>a;
				if(ar[a]==0) {count++;++ar[a];} 	
			}
		/*sort(ar,ar+n);
		for(int i=0;i<n;){
			int k = std::count(ar,ar+n,ar[i]);
			i+=k;
			count++;
		}*/
		cout<<count<<"\n";
	}
	return 0;
} 
