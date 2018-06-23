    #include<iostream>
     
    using namespace std;
     
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
                  int n;
                  scanf("%d",&n);
                  if(n%2)
                  printf("BOB\n");
                  else
                  printf("ALICE\n");              
        }
        return 0;    
    }
      
