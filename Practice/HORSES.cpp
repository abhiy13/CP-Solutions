    #include<iostream>
    #include<algorithm>
    using namespace std;
    int main()
    {
        int tests,num,x,min;
        scanf("%d",&tests);
        for(int i=0;i<tests;i++)
        {
                scanf("%d",&num);
                int a[num];
                for(int j=0;j<num;j++)
                scanf("%d",&a[j]);
                sort(a,a+num);
                min=1000000001;
                for(int j=0;j<num-1;j++)
                {
                        x=a[j+1]-a[j];
                        if(x<min)
                        min=x;
                        }
                        printf("%d\n",min);
        }
        return 0;
    }  
