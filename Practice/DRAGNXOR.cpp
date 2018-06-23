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
		ll n  , a , b;
		cin>>n>>a>>b;
		ll ca = 0 , cb = 0;
		while(a){
			if(a&1) ca++;
			a>>=1;
		}
		while(b){
			if(b&1) cb++;
			b>>=1;
		}	
		ll res = 0;
		ll sum = ca+cb;
		for(int i = n-1 ; i >= 0 and sum > 0 ; i-- , sum--){
			res |= (1<<i);
		}
		sum = ca+cb-n;
		for(int i = 0 ; i < sum ; i++){
			res &= ~(1<<i);
		}
		cout<<res<<endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
