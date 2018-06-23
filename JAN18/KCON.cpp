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
#define pll pair<ll,ll>
#define pb(x) push_back(x)
#define f first
#define se second
 
typedef long long ll;
typedef unsigned long long llu;
 
ll mm[3]={0,0,0};
 
ll maxSubArraySum(ll a[], ll size , ll k){
   ll msf = a[0];
   ll cm = a[0];
   int pp = -1;
   for (int i = 1; i < size; i++)
   {
        cm = max(a[i], cm+a[i]);
        msf = max(msf, cm);
        if((i+1)%k==0){
            mm[++pp] = msf;
        }
   }
   return msf;
}
 
int main(){
    #ifdef ABHI
        freopen("input.txt" , "r" , stdin);
    #endif
    io;
    int t;
    cin>>t;
    for(int qq = 1 ; qq<=t ; qq++){
        ll n=0 , k=0;
        cin>>n>>k;
        ll ar[n+n+n];
        ll summ = 0;
        ll smm = 0;
        for(ll i = 0 ; i < n ; i++) {
            cin>>ar[i];
            summ+=ar[i];
            ar[n+i] = ar[i];
            ar[n+n+i] = ar[i];
            smm += ar[i]+ar[i]+ar[i];
        }
        if(k==1){
            cout<<maxSubArraySum(ar,n,n)<<endl;
            continue;
        }else if(k==2){
            cout<<maxSubArraySum(ar,(ll)(n+n),n)<<endl;
            continue;
        }
        ll su = maxSubArraySum(ar,n+n+n,n);
        if(k==3){cout<<su<<endl;continue;}
        if(su == accumulate(ar,ar+n+n+n,0)){
            cout<< (ll)summ*(k) <<endl;
        }else{
            if(mm[1]==mm[2]){
                cout<<su<<endl;
            }else{
                ll factor = (summ*k)-(smm-su);
                cout<<factor<<endl;
            }
        }
 
    }
    #ifdef ABHI
        cerr<<"Time Elapsed "<<(double)1000.00*clock()/CLOCKS_PER_SEC <<" ms\n"; 
    #endif
    return 0;
}    
