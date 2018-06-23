#include "bits/stdc++.h"
	using namespace std;
 
typedef long long ll;
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	cout.precision(20);
	cout << fixed;
	int T;
	cin>>T;
	while(T--){
		ll n , a , b;
		cin>>n>>a>>b;
		map <ll , ll> ar;
		ll x; double  res = 0.0;
		for(int i = 0 ; i < n ; i++){
			cin>>x;
			ar[x]++;
		}
		res = (double)(ar[a]*ar[b])/(double)(n*n);
		cout<<res<<endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
