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
 
string s;
 
int main() {
  int t;
  cin>>t;
  while(t--){
    cin>>s;
    int k = s.size();
    stack <char> p;
    for (int i = k-1 ; i >= 0 ; i--)
    {
        if(s[i]=='*') {
            if(!p.empty()) p.pop();
            if(!p.empty()) p.pop();
        }else{
          p.push(s[i]);
        } 
    }
    if(p.empty()) cout<<"YES\n";
    else cout<<"NO\n";
  }
	return 0;
}
 
