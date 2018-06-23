    #include<stdio.h>
    #include<string.h>
    int main()
    {
    int t,n,l;
    char s[12];
    scanf("%d",&t);
    while(t--)
    {
    scanf("%s",s);
    l=strlen(s);
    if(s[l-1]%2!=0)
    s[l-1]--;
    printf("%s\n",s);
    }
    return 0;
    }   
