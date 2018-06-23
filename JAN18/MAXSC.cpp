/*
    Author: abhiy13(Abhishek)
    Int Elligence;
    ChandigAh University
    Time:-: dd:mm:yyyy hr:mm
*/
#include <bits/stdc++.h>
    using namespace std;
 
#define ms(x) memset(x,0,sizeof(x));
typedef long long int ll;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n; 
        ll ar[n][n];
        ll ma[n]={0};
        for (ll i = 0; i < n ; i++) {
             for(ll j = 0; j < n; j++) {
                  cin>>ar[i][j];
                  ma[i] = max(ar[i][j],ma[i]);
             }
        }
        ll sum = 0;
        int flag = 0;
        for (ll i = n-2; i >= 0 ; i--) {
             ma[i]=0;
             for (ll j = 0; j < n; j++) {
               if(ar[i][j]>ma[i] && ar[i][j]<ma[i+1]){
                    ma[i] = ar[i][j];
               }
             }
             if(ma[i]==0) {flag=1;break;}
             else sum+=ma[i];
        }
        sum+=ma[n-1];
        if(!flag) cout<<sum<<endl;
        else cout<<"-1\n";
    }
}   
