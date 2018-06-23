#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	cin>>t;
	while(t--)      
	{
	    int a ,b;
	    cin>>a>>b;int i=0;int msum=0;int n =0;
	    if(a>b) n = a;
	    else n = b;
	    while(n>=0){
	         int c=0;
		 if(a>0) c= a%10;
		 int d =0;
	         if(b>0) d = b%10;
	       /*  c*=pow(10,i);
	         d*=pow(10,i);*/
	         int sum = c+d;
	         if(sum>=10) sum-=10;
	         sum*=pow(10,i);  
		//cout<<sum<<"\t";
		 msum+=sum;
	         a=a/10;
	         b/=10;
		 n/=10;
	         if(n==0)
	          break;
	         i++;
	    }
	    cout<<msum<<"\n";
	}
	return 0;
}
 
