#include<bits/stdc++.h>
     using namespace std;
bool check(int ar[],int n){
     for(int i=0;i<n-1;i++){
          if(ar[i]!=ar[i+1])
               return false;
     }
     return true;
}
int factorial(int n)
{
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}
int main(){
     int t;
     cin>>t;
     while(t--){
    	     int n;
    	     cin>>n;int tc=0;
    	     int ar[n];int count=0;int max=0;int nc=1;
    	     for(int i=0;i<n;i++) {
			cin>>ar[i];
			for(int j=0;j<i;j++){
			   if(ar[i]+ar[j]>max) max=ar[i]+ar[j];
			}
		}
	      for(int i=0;i<n;i++) {
			for(int j=0;j<i;j++){
			   if(ar[i]+ar[j]==max) count++;
			   else nc++;
				tc++;
			}
		}
 
               int k = n-1;
		double m=0;
	      /* if(n>0)
                m = (double)count/(nc-1);//(double)2*count/(double)(factorial(n));
		else
		m = (double)count/nc;
               printf("%.9f\n",m); */
		//m = (double)count;
 m = (double)count/(tc);//(double)2*count/(double)(factorial(n));
	
               printf("%.9f\n",m);
		
    	}
     return 0;
} 
