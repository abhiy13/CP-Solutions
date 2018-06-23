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
        assert(n>1);
        cout<<n<<"\n";
        for(int i = 0 ; i < n ; i ++){
            cout<<n<<"\n";
            for(int j = 0 ; j < n ; j++){
                cout<<j+1<<" "<<(i+j)%n+1<<" "<<(i+j+1)%n+1<<"\n";
            }    
        }    
    }
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
