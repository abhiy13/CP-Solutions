#include <bits/stdc++.h>
#include <string>
using namespace std;
 
int main() {
	int t;
	cin>>t;
	int e =0  , o =0;
	for(int i=1;i<=t;i++) {
	     int a =0;
	     cin>>a;
	     if(a%2==0) e++;
	     else o++;
	   	}
	if(e>o) cout<<"READY FOR BATTLE";
	else cout<<"NOT READY";
	return 0;
}
 
