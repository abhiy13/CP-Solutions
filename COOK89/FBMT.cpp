#include <bits/stdc++.h>
	using namespace std;                     
 
int main(){
	int t;
	cin>>t;
	while(t--){                        
		int n;
		cin>>n;
		if(n==0) {cout<<"Draw\n";continue;}
		string s[n];
		for(int i = 0; i < n ; i++){
			cin>>s[i];
		}	
		sort(s,s+n);
		string k = s[0];
		string s2;
		int k1=0,k2=0;                     
		for(int i = 0; i < n ; i++){
			if(!s[i].compare(k)) k1++;
			else {s2=s[i];k2++;}		
		}
		if(k1==k2) cout<<"Draw\n";
		else if(k1>k2) cout<<k<<"\n";
		else if(k2>k1) cout<<s2<<"\n";
	}
	return 0;
} 
