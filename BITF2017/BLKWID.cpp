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
  int n;
  cin>>n;
  int ar[n][n];
  for(int i = 0; i < n ; i++){
    for(int j = 0 ; j < n ; j++)
      cin>>ar[i][j];
  }
  for(int i = 0 ; i < n ; i++){
    for(int j = n-1 ; j >= 0 ; j--)
      cout<<ar[j][i]<<" ";
      cout<<endl;
  }
	return 0;
}
 
