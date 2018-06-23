#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s , m;int j=0;int count=0;
	    cin>>s>>m;
	    for(int i=0;i<m.length();i++){
	         for(int j=0;j<s.length();j++)
	         {
	              if(m[i]==s[j]){count++;break;}
	         }
	    }
	     cout<<count<<"\n";
	}
	return 0;
}
 
