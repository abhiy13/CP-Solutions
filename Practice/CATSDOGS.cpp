#include <bits/stdc++.h>
	using namespace std;
 
#define debug(x) cout<<x<<"\n";
#define io ios::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n"
#define pi  pair<int,int>
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define f first
#define se second
 
typedef long long LL;
typedef unsigned long long ULL;
 
int main() {
	io;
  LL t;
     cin>>t;
     while(t--){
        LL c, d , l;
        cin>>c>>d>>l; 
        if(l%4!=0 || ((c+d)*4)<l || (d*4>l)){
            cout<<"no\n";
        }else{
            int animals = l/4;
            animals =animals-d+d*2;
            if(c>animals) cout <<"no\n";
            else cout<<"yes\n";
        }
     }
	return 0;
}
 
