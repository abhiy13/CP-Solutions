#include "bits/stdc++.h"
	using namespace std;
 
#define io std::ios::sync_with_stdio(false);
#define FOR(i,n) for(ll i = 0 ; i < n ; i++)
#define FORR(i,a,b) for(ll i = a ; i < b ; i++)
#define RFOR(i,a,b) for(ll i = a ; i > b ; i--)	
#define ll long long
#define llu unsigned long long
#define pub(x) push_back(x)
#define emb(x) emplace_back(x)
#define mkp(a,b) make_pair(a,b)
#define ff first
#define ss second
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	ll n , k;
	cin>>n>>k;
	ll ar[n+1];
	memset(ar,0,sizeof(ar));
	string s[] = {"CLICK" , "CLOSEALL"};
	string ss;
	ll x , count = 0;
	FOR(i,k){
	     cin>>ss;
          if(ss == s[1]){
               count = 0;
               memset(ar,0,sizeof(ar));
          }else{
               cin>>x;
               if(ar[x]==1){
                    count--;
                    ar[x] = 0;
               }else{
                    count++;
                    ar[x] = 1;
               }
          }
          cout<<count<<endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
