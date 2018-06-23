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
	//	freopen("input.txt" , "r" , stdin);
	#endif
	int T;
	cin>>T;
	while(T--){
		ll n;
		cin>>n;
		if(n&1){
			cout<<-1<<endl;
		}else{
			cout<<n/4+1<<endl;
		}
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
