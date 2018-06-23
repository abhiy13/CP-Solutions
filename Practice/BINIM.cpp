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
		int n; string s , ss;
		cin>>n>>s;
		int d0 = 0 , d1 = 0;
		for(int i = 0 ; i < n ; i++){
			cin>>ss;
			if(ss[0]=='0'){
				for(auto &c : ss) d0 += (c=='0');
			}else{
				for(auto &c : ss) d1 += (c=='1');
			}
		}	
		if(s=="Dee"){
			cout<<(d0 > d1 ? "Dee" : "Dum") <<endl;
		}else{
			cout<<(d1 > d0 ? "Dum" : "Dee") <<endl;
		}
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
