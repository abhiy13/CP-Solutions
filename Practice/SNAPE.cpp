#include <bits/stdc++.h>
  int main()
    {
     int t;
     float a,b,c,d;
     scanf("%d",&t);
 
     while(t--)
       {
        scanf("%f %f",&a,&b);
 
 
 
        c=sqrt((b*b)-(a*a));
        d=sqrt((b*b)+(a*a));
 
         printf("%f %f\n",c,d);
       }return (0);
    } 
