#include <bits/stdc++.h>
	using namespace std;
int main()
{
     int t;
     cin>>t;
     while(t--){
          int n;int k;
          cin>>n>>k;
          vector <int> a(n);
          for(int i=0;i<n;i++) cin>>a[i];
          sort(a.begin(),a.end());
          int m = ((n+k)/2);
          //cout<<m<<a[m];
          cout<<a[m]<<"\n";
     }
     return 0;
} 
