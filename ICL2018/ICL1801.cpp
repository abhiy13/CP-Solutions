/*
 *	Abhishek(abhiy13)
 *	Chandigarh University
*/
 
#include "bits/stdc++.h"
	using namespace std;
 
#define io std::ios::sync_with_stdio(false);
#define FOR(i,n) for(int i = 0 ; i < n ; i++)
#define rep(i,a,b) for(int i = a ; i < b ; i++)
#define rrep(i,a,b) for(int i = a ; i > b ; i--)
#define timer cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
#define all(x) begin(x),end(x)
 
typedef long long ll;
typedef unsigned long long llu;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const int mod = 1e9+7;
 
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int t;
	cin>>t;
	while(t--){
		int n , m;
		cin>>n>>m;
		ll qq = n*m;
		ll ar[qq];
		FOR(i,qq) cin>>ar[i];
		sort(ar,ar+qq,greater<int>());
		int ii = 1;
		ll sum1 = 0 , sum2 = 0;
		FOR(i,qq){
			//cout<<ar[i]<<" ";
			if(ii < 0) sum2 += ar[i];
			else sum1 += ar[i];
			ii*=-1;
			//cout<<ar[i]<<endl;
		}
		//cout<<sum1<<" "<<sum2<<endl;
		if(sum1>sum2) cout<<"Cyborg\n";
		else if(sum2>sum1) cout<<"Geno\n";
		else cout<<"Draw\n";
	}
	#ifdef ABHI
		timer
	#endif
	return 0;
} 
