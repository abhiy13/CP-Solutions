/******************************************
*  AUTHOR:         ABHISHEK YADAV         *
*  INSTITUITION:   CHANDIGARH UNIVERSITY  *
******************************************/
#include <bits/stdc++.h>
	using namespace std;
 
typedef long long ll;
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int T;
	cin>>T;
	while(T--){
		ll n;
		cin>>n;
		ll x;
		ll res = 1000000000000;
		for(int i = 0 ; i < n ; i++){
			cin>>x;
			res = min(res,x);
		}
		n--;
		cout<<n*res<<endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
