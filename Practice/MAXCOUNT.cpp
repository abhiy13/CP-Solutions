#include <bits/stdc++.h>
	using namespace std;
 
#define debug(x) cout<<x<<"\n";
#define io ios::sync_with_stdio(false);cin.tie(NULL);
 
typedef long long LL;
typedef unsigned long long ULL;
 
 
int main(){
    int t;
    cin>>t;
    while(t--){
        LL n;
        cin>>n; 
        LL ar[n];
        for(int i = 0 ; i < n ; i++) cin>>ar[i];
        sort(ar,ar+n);
        LL max=0,mm=1000;
        for(LL i = 0 ; i < n ; i++) {
            LL k = std::count(ar,ar+n,ar[i]);
            if(k>max) {
                max = k;
                mm = ar[i];
            }else if(k==max){
               mm=min(ar[i],mm);
            }
            i+=k-1;
        }
        cout<<mm<<" "<<max<<"\n";
    }
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
