#include <iostream>
#include <cstring>
	using namespace std;
#define max 100000
int main()
{
int t;
cin>>t;
while(t--)
	{
	string a; int flag=0;
	cin>>a;
	for(int i=0;i<a.length();i++)
	     if((a[i]=='E'&&a[i+1]=='C')||(a[i]=='S'&&a[i+1]=='C')||(a[i]=='S'&&a[i+1]=='E'))
	          flag=1;
	if(flag==1)
		cout<<"no"<<endl;
	else 
		cout<<"yes"<<endl;	
	}
 
return 0;
} 
