    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define mod 1000000007
    int main() 
    {
    	ll n,k;
    	scanf("%lld %lld",&n,&k);
    	if(n<=k|| k==1)
    	 printf("1\n");
    	else
    	{
    	    ll a[n+1]={0};
    	    a[1]=1;
    	    if(k!=1)
    	    {
    	        for(ll i=2;i<=k;i++)
    	        {
    	            a[i]=((a[i-1]%mod)+1)%mod;
    	        }
    	        a[k+1]=a[k];
    	        for(ll i=k+2;i<=n;i++)
    	        {
    	            if((i-k-1)>k)
    	             a[i]=(((2*(a[i-1]%mod))%mod)-(a[i-k-1]%mod))%mod;
    	            else
    	             a[i]=(((2*(a[i-1]%mod))%mod)-1)%mod;
    	        }
    	        /*for(ll i=1;i<=n;i++)
    	         cout<<a[i]<<" ";
    	        cout<<endl;*/
    	        printf("%lld\n",a[n]);
    	    }
    	}
    	return 0;
    }  
