#include <bits/stdc++.h>
	using namespace std;
 
#define debug(x) cout<<x<<"\n";
#define io ios::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n"
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define f first
#define se second
 
typedef long long LL;
typedef unsigned long long ULL;
 
void cal(int ind , int n){
    int ar[7];
    memset(ar,0,sizeof(ar));
    for(int i = 0 ; i < n ; i++){
        ar[ind]++;
        ind++;
        if(ind>=7) ind=0;
    }
    for(int i = 0 ; i < 7 ; i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}
 
int main() {
	io;
     int t;
     cin>>t;
     while(t--){
            string arr[]={ "mon", "tues", "wed", "thurs", "fri", "sat" , "sun"};
            int n;
            string s;
            int ind=0;
            cin>>n>>s; 
            for(int i = 0 ;i < 7 ; i++){
                if(s==arr[i]){
                    ind=i;
                    break;
                }    
            }
            cal(ind,n);
     }
	return 0;
}
 
