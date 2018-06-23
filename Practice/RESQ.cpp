#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    int i;
    int j,k,m,n,p;
    for(p=0;p<t;p++)
    {
              scanf("%d",&n);
              m=sqrt(n);
              
              for(i=m;i>=1;i--)
              {
                               if(n%i==0)
                               {
                                    //cout<<i<<n/i<<-i+(n/i)<<endl;
                              printf("%d\n",-i+(n/i));
                               break;
                               }
              }
    } 
    return 0;
}    
