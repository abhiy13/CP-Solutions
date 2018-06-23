/*
	Abhishek (abhiy13)
	Contest :: LTIME56
	Chandigarh University
*/
#include "bits/stdc++.h"
	using namespace std;
 
typedef long long ll;
 
int main(){
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int t;
	cin>>t;
	for(int tt = 1 ; tt <= t ; tt++){
		int n;
		cin>>n;
		vector <int> ar(n);
		int o = 0;
		int e = 0;
		int res = 0;
		for(int i = 0 ; i < n ; i++) {
			cin>>ar[i];
			if(ar[i]%2 != 0) o++;
		}
		if(o%2!=0) res = 2;
		else res =1;
		cout<<res<<endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed " << (double)1000.00*clock()/CLOCKS_PER_SEC << " ms\n";
	#endif
	return 0;
} 
