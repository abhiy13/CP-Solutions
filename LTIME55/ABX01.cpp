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
 
ULL fun(ULL q){
    if(q<=9) return q;
    ULL sum=0;
    for(ULL i=q ; i>=1 ; i/=10){
        sum+=i%10;
    }
    return fun(sum);
}
 
 
int main() {
	io;
    int t;
     cin>>t;
     while(t--){
        int p;
        ULL n;
        cin>>n>>p;
        ULL q;
   	    q = (pow(n,p));
        cout<<fun(q)<<endl;
     }
	return 0;
}
 
