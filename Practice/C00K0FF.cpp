#include <iostream>
#include <string.h>
using namespace std;
 
int main() {
	int t;
	cin>>t;
	while(t--)
	{    
	     int n;
	     cin>>n;
	     int found[5]={0};
	     string s[n];
		for(int i=0;i<n;i++){cin>>s[i];
		if(s[i]=="cakewalk")found[0]=1;
		if(s[i]=="simple")found[1]=1;
		if(s[i]=="easy")found[2]=1;
		if(s[i]=="easy-medium")found[3]=1;
		if(s[i]=="medium")found[3]=1;
		if(s[i]=="medium-hard")found[4]=1;
		if(s[i]=="hard")found[4]=1;}
		int sum=0;
     	for(int i=0;i<5;i++){
		sum+=found[i];
     	}
     	if(sum==5)cout<<"Yes"<<endl;
     	else cout<<"No"<<endl;
	}
	
	return 0;
}
 
