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
	int t;
	cin>>t;
	FOR(tt,t){
          ll n  , x;
          cin>>n>>x;
          ll ar[n];
          FOR(i,n) cin>>ar[i];
          double low = 0 , high = 10000;
          FORR(i,1,60){
               double mid = (low+high)/2.0;
               vector <double> temp;
               FOR(i,n) temp.push_back(ar[i]*(i+1) - mid*(i+1));
               sort(temp.rbegin() , temp.rend());
               double sum = 0.0;
               bool ok = false;
               FOR(i,x){
                    sum += temp[i];
               }
               ok = (sum>=0) ? true : false;
               if(ok){
                    low = mid;
               }else{
                    high = mid;
               }
          }
          printf("%.20lf\n",low);
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
