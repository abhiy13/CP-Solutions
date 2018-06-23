/****************************************************
*****************************************************
**               Abhishek(abhiy13)                 **          
**             Chandigarh University               **
**   https://www.youtube.com/watch?v=r6zIGXun57U   **
*****************************************************
****************************************************/ 
 
 
#include "bits/stdc++.h"
	using namespace std;
 
 
//`````````````````````````````````````````````````````Random Stuff Here```````````````````````````````````````````````````````//
	
#define io std::ios::sync_with_stdio(false);
#define FOR(i,n) for(ll i = 0 ; i < n ; i++)
#define FORR(i,a,b) for(ll i = a ; i < b ; i++)
#define RFOR(i,a,b) for(ll i = a ; i > b ; i--)	
#define all(x) begin(x),end(x)
#define SZ(x) x.size()
#define ll long long
#define llu unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define mp(a,b) make_pair(a,b)
#define clr(x) memset(x,0,sizeof(x))
#define vclr(x,y) memset(x,y,sizeof(x))
#define rsort(x) sort(x.rbegin(),x.rend())
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define TRACE
 
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif   
 
 
//``````````````````````````````````````````````````````Start of Program`````````````````````````````````````````````````//
 
 
const int inf = 1e9;
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int t;
	cin>>t;
	FOR(tt,t)
	{
		ll n,m;
		cin>>n>>m;
		ll ar[n][m];
		ll br[n][m];
		for(ll i=0;i<n;i++){
			for(ll j=0;j<m;j++){
				cin>>ar[i][j];
			}
		}
		for(ll i=0;i<n;i++){
			for(ll j=0;j<m;j++){
               if(i==0 && j==0){
                   if(ar[i][j]==-1){
                        br[i][j]=1;
                   }
                   else{	
                   	br[i][j]=ar[i][j];
                   }
               }
               else
               	if(i==0 && j!=0){
                    if(ar[i][j]==-1){
                    	br[i][j]=br[i][j-1];
                    }
                    else
                    	br[i][j]=ar[i][j];
               	}
               	else
               		if(i!=0 && j==0){
               			if(ar[i][j]==-1){
               				br[i][j]=br[i-1][j];
               			}else{
               				br[i][j]=ar[i][j];
               			}
               		}
               		else{
               		  	if(ar[i][j]==-1){
               		  		if(br[i][j-1]>br[i-1][j]){
                                br[i][j]=br[i][j-1];
               		  		}else{
                                br[i][j]=br[i-1][j];
               		  		}
               		  	}else{
               		  		br[i][j]=ar[i][j];
               		  	}
               		  }
 
 
			}
		}
		     	int flag=0;
                 for(ll i=0;i<n;i++){
                 	for(ll j=0;j<m;j++){
                        if(i==0 && j==0){
                        	continue;
                        }else
                        	if(i==0 && j!=0){
                        		if(br[i][j]<br[i][j-1]){
                        				flag=1;
                        				break;
                        			}
                        	}
                        	else
                        		if(i!=0 && j==0)
                        		{
                        		     if(br[i][j]<br[i-1][j])
                        		     {
                        		     	flag=1;
                        		     	break;
                        		     }
                        		}
                        		else
                        		{
                        			if(br[i][j]<br[i-1][j] || br[i][j]<br[i][j-1])
                        			{
                        				flag=1;
                        				break;
                        			}
                        		}
                 	}
                 	if(flag==1)
                 		break;
                 }
 
                 if(flag==1)
                 {
                 	cout<<-1<<endl;
                 }
                 else
                 {
                 	for(ll i=0;i<n;i++)
                 	{
                 		for(ll j=0;j<m;j++)
                 		{
                 			cout<<br[i][j]<<" ";
                 		}
 
                 		cout<<endl;
 
                 	}
 
                 }
		}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
