#include <bits/stdc++.h>
     using namespace std;
int main()
{
     int t;
     cin>>t;
     while(t--){
      int n;
      cin>>n;
      vector <int> a(n);int flag = 1;
      for(int i=0;i<n;i++)
      {
           cin>>a[i];
      }
      if(n%2==0){
           cout<<"no"<<endl;
           continue;
      }
      if(a[0]!=1){
           cout<<"no"<<endl;
           continue;
      }
      if((a[n/2]>=a[n/2+1]||a[n/2+1]<=a[n/2+2]))
          for(int i=0;i<n/2;i++)
      {
           if(a[i]==a[n-i-1]&&a[i+1]-a[i]==1)
           {
 
           }
           else {flag=0;break;}
      }
      else flag=0;
      if (flag == 0)
          cout<<"no"<<endl;
     else 
          cout<<"yes"<<endl;
     }
     return 0;
} 
