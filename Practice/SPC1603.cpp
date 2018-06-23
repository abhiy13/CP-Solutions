#include <bits/stdc++.h>
	using namespace std;
 
#define debug(x) cout<<x<<"\n";
#define MOD 1e7 + 7;
#define mod 1e9;
#define io ios::sync_with_stdio(false);cin.tie(NULL);
 
typedef long long LL;
typedef unsigned long long ULL;
 
int main() {
	io;
    string n;
    cin>>n;
    ULL k = 0;
    ULL p = 1;
    while(1){
        p=1;
        k=n.size();
        if(k==1) break;
        for(ULL i = 0 ; i < k ; i++){
           p*=(n[i]=='0')?1:n[i]-'0';
        }
        n=to_string(p);
    }
    printf("%c" , n[0]);
	return 0;
}
 
