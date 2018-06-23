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
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    #endif
	io;
    string s;
    int t;
    cin>>t>>s;
    while(t--){
        string k;
        cin>>k;
        int mm = k.size();
        for(int i = 0 ; i < mm ; i++){
            if(k[i]=='_') k[i]=' ';
            else if(isupper(k[i])) k[i] = toupper(s[k[i]-'A']);
            else if(islower(k[i])) k[i] = s[k[i] - 'a'];
        }
        cout<<k<<endl;
    }
    #ifndef ONLINE_JUDGE
    cerr<<"Time Elapsed "<<(double)1000*clock()/CLOCKS_PER_SEC<<" ms\n";
    #endif
    return 0;
}
 
