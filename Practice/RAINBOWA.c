#include<stdio.h>
int main()
{
    int t,i,arr[100],n,p;
    scanf("%d",&t);
    while(t--)
    {
    scanf("%d",&n);
     p=0;
    for(i=0;i<n;i++)
    {
    scanf("%d",&arr[i]);
    }
    if(arr[n/2]==7)
    {
 
    for(i=0;i<n/2;i++)
    {
    if(arr[i]!=arr[n-1-i])
    {
        p=-1;
        break;
    }
    }
    }
    else
    p=-1;
    if(p==-1)
        printf("no\n");
    else
        printf("yes\n");
}
return 0;
} 
