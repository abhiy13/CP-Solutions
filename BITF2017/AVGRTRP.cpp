#include <bits/stdc++.h>
    using namespace std;
int main() {
     
    long long int t,n,dist,no_conn,no_cables;
    scanf("%ld",&t);
    long long int cable[t];
    for(int j=0;j<t;j++)
    {
            cable[j]=0;
    }  
    for(int i=0;i<t;i++)
    {
        scanf("%lld",&n);
        long long int city[n],person[n];
        for(long long int j=0;j<n;j++)
        {
            scanf("%lld",&city[j]);
        }    
        for(long long int j=0;j<n;j++)
        {
            scanf("%lld",&person[j]);
        }  
        for(long long int j=0;j<n-1;j++)
        {
            for(long long int k=j+1;k<n;k++)
            {
               if(person[k]>person[j])
                   no_conn=person[k];
                else
                    no_conn=person[j];
               dist=abs(city[k]-city[j]);
               no_cables= no_conn*dist;
               cable[i]=cable[i] + no_cables; 
            }    
        }    
    }  
    for(int i=0;i<t;i++)
        printf("%lld\n",cable[i]%1000000007);
 
    return 0;
} 
