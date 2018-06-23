        #include<cstdio>
        int main()
        {
        int t,x1,x2,y1,y2,i;
        scanf("%d",&t);
        for(i=1;i<=t;i++)
        {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1>x2&&y1==y2)
        printf("left\n");
        else if(x1<x2&&y1==y2)
        printf("right\n");
        else if(x1==x2&&y1>y2)
        printf("down\n");
        else if(x1==x2&&y1<y2)
        printf("up\n");
        else
        printf("sad\n");
        }
        return 0;
        }   
