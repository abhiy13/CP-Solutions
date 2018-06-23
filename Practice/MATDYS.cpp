#include "bits/stdc++.h"
	using namespace std;
 
int main(){
	int t;
	cin>>t;
	while(t--){
		unsigned long long n , m;
		cin>>n>>m;
		unsigned long long res = 0;
		for(;n>=1;n--){
			if(m&1){
				res += (1ull<<(n-1));
			}
			m>>=1;
		}
		cout<<res<<endl;
	}
	return 0;
} 
