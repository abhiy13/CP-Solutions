    #include <bits/stdc++.h>
    #include <string>
    using namespace std;
    #define rep(a) for(int i=0;i<a;i++)
    int main() {
         ios::sync_with_stdio(0);
         cin.tie(NULL);
    	int t;
    	cin>>t;
    	while(t--)
    	{
    	     int n;int flag=0;
    	     cin>>n;
    	     int z=0,o=0,m=0,ot=0;
    	     rep(n){
    	          int a;
    	          cin>>a;
    	          if(a==0) z++;
    			else if(a==1) o++;
    			else if(a==-1) m++;
    			else ot++;
    	     }
              if(ot>1)cout<<"no\n";
             	else if(m && ot) cout<<"no\n";
    		else if(m>1 && !o) cout<<"no\n";
    		else cout<<"yes\n";
    	 }
    	
    	return 0;
    } 
