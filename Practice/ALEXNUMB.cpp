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
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    #endif
    int t;
     cin>>t;
     while(t--){
        long n;
        cin>>n;
        ULL ct =0;
        ULL arr[n];
        for(int i = 0 ; i < n ; i++) cin>>arr[i];
        cout<<(n*(n-1))/2<<endl;
     }
    #ifndef ONLINE_JUDGE
    cerr<<"Time Elapsed " << (double)1000*clock()/CLOCKS_PER_SEC <<" ms\n";
    #endif
	return 0;
}
 
