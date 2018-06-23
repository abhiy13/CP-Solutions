/****************************************************
*****************************************************
**               Abhishek(abhiy13)                 **          
**             Chandigarh University               **
**   https://www.youtube.com/watch?v=r6zIGXun57U   **
*****************************************************
****************************************************/ 
 
 
/*
4 6
4 2 1 8
1 2
1 3
1 4
2 3
2 4
3 4
*/
#include<bits/stdc++.h>
using namespace std ;
#define ll long long
int main()
{
  ll n,q ;
  cin>>n>>q ;
  ll r[n+1] ;
  for(ll i=1;i<=n;i++)
    cin>>r[i] ;
  ll dp[n+1][n+1] ;
  for(ll i=1;i<=n;i++)
  {
      for(ll j=i+1;j<=n;j++)
      {
          dp[i][j]=__gcd(r[i],r[j]) ;
      }
  }
  while(q--)
  {
      ll a,b,u=INT_MIN ;
      cin>>a>>b ;
      for(ll i=a;i<=b;i++)
      {
          for(ll j=i+1;j<=b;j++)
          {
              u=max(u,dp[i][j]) ;
          }
      }
      cout<<u<<endl ;
 
  }
}
 
