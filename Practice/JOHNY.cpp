#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	 long n , k;long m=0;
	 cin>>n;
	 vector <long> a(n);
	 for(int i=0;i<n;i++) cin>>a[i];
	 cin>>k;
	 long p = a[k-1];
	 sort(a.begin(),a.end());
	 for(long i=0;i<n;i++){
	      if(a[i]==p){
	           m=i+1;
	           break;
	      }
	 }
	 cout<<m<<"\n";
	}
	
	return 0;
}
 
