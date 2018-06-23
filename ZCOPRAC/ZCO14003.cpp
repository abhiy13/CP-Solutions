#include <bits/stdc++.h>
#include <string>
using namespace std;
 
int main() {
	int t;
	cin>>t;
	vector <long long> a(t);
	vector <long long> ar(t);
	for(int i=0;i<t;i++) cin>>a[i];
	std::sort(a.begin(),a.end());
	for(int i=0;i<t;i++){
	     ar[i]=a[i]*(t-i);
	}
	cout<<*std::max_element(ar.begin(),ar.end());
	return 0;
}
 
