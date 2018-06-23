#include <bits/stdc++.h>
     using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	     int n;
	     cin>>n;
	     vector <int> ar(n);int flag=0;
	     for(int i=0;i<n;i++) cin>>ar[i];
	     sort(ar.begin(),ar.end());
	     for(int i=0;i<n;i++){
	          int c  = std::count(ar.begin(),ar.end(),ar[i]);
	          if(c==1) {flag=ar[i];break;}
	     }
	     cout<<flag<<"\n";
	}
	return 0;
}
 
