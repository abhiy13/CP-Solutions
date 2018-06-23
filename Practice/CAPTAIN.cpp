#include <bits/stdc++.h>
	using namespace std;
 
#define debug(x) cout<<x<<"\n";
#define io ios::sync_with_stdio(false);cin.tie(nullptr);
 
typedef long long LL;
typedef unsigned long long ULL;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;  
        cin>>n;
        int ar[n];
        for(int i = 0 ; i < n ; i++) cin>>ar[i];
        sort(ar,ar+n);
        bool flag = false;
        for(int i = 0 ; i < n -2 ; i++){
            if(ar[i]+ar[i+1]>ar[i+2] && ar[i]-ar[i+1]<ar[i+2]) {flag=true;break;}            
        }    
        if(flag==true){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
