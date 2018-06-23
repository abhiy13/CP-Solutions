/******************************************
*  AUTHOR:         ABHISHEK YADAV         *
*  INSTITUITION:   CHANDIGARH UNIVERSITY  *
******************************************/
#include "bits/stdc++.h"
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
		ll a, b , c;
		cin>>a>>b>>c;
		ll abc = (a+b+c)/3;
		if(a==b and b==c){
			cout<<0<<endl;
		}else if(a==abc or b==abc or c==abc){
			cout<<1<<endl;
		}else{
			cout<<2<<endl;
		}
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
