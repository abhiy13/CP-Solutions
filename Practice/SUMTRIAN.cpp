#include<stdio.h>
int main()
{
    int r,i,j,t;
    int a[100][100];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&r);
        for(i=0;i<r;i++)
            for(j=0;j<=i;j++)
            scanf("%d",&a[i][j]);
            for(i=r-1;i>0;i--)
                for(j=0;j<i;j++)
            {
                if(a[i][j]>a[i][j+1])
                    a[i-1][j]+=a[i][j];
                else
                    a[i-1][j]+=a[i][j+1];
            }
            printf("%d\n",a[0][0]);
    }
 return 0;
}
 
