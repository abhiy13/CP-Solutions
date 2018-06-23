#include <bits/stdc++.h>
#include <cctype>
     using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	     int sum=0;
	     string s;
	     cin>>s;
	     for(int i=0;i<s.size();i++) if(isdigit(s[i])){
	          int m = 0; 
	          m = s[i] - '0';
	          sum+=m;
	     }
	     cout<<sum<<"\n";
	}
	return 0;
}
 
