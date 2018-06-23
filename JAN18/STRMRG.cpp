/*
    Author: abhiy13(Abhishek)
    Int Elligence;
    Chandigarh University
    Time:-: dd:mm:yyyy hr:mm
*/
#include <bits/stdc++.h>
  using namespace std;
 
 
#define io ios::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
#define pll pair<llu,llu>
#define pb(x) push_back(x)
#define f first
#define se second
 
typedef long long ll;
typedef unsigned long long llu;
 
void re(char* S , ll n){
 
   if (n < 2)
     return;
 
   int j = 0;
   for (int i=1; i<n; i++)
   {
       if (S[j] != S[i])
       {
           j++; 
           S[j] = S[i];
       }     
   }   
   j++;
   S[j] = '\0';     
}
 
ll sol(char *X, char *Y, ll m, ll n ){
   ll L[m+1][n+1];
   for (ll i=0; i<=m; i++)
   {
     for (ll j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
   return L[m][n];
}
 
int main(){
  #ifdef ABHI
    freopen("input.txt" , "r" , stdin);
  #endif
    io;
    int t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        char a[n],b[m];
        cin>>a>>b;
        re(a,n);re(b,m);
        n = strlen(a);
        m = strlen(b);
        ll pp = sol(a,b,n,m);
        cout<<n+m - pp<<endl;
    }
  #ifdef ABHI
    cerr<<"Time Elapsed "<<(double)1000.00*clock()/CLOCKS_PER_SEC <<" ms\n"; 
  #endif
  return 0;
} 
