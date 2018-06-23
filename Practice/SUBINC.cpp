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
 
int main() {
	io;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        LL ar[n];
        for(LL i = 0 ; i < n ; i++) cin>>ar[i];
        vector <LL> a(n); 
        a[0]=1;
        LL sum=0;
        for(LL i = 1 ; i< n ; i++){
            if(ar[i-1]<=ar[i]) a[i]=a[i-1]+1;
            else a[i]=1;
        }
        for (LL i = 0; i < n; i++) sum+=a[i];
        cout<<sum<<endl;
    }
	return 0;
}
 
