    #include "bits/stdc++.h"
    	using namespace std;
     
    #define io std::ios::sync_with_stdio(false);
    #define FOR(i,n) for(ll i = 0 ; i < n ; i++)
    #define FORR(i,a,b) for(ll i = a ; i < b ; i++)
    #define RFOR(i,a,b) for(ll i = a ; i > b ; i--)	
    #define ll long long
    #define llu unsigned long long
    #define pii pair<int,int>
    #define pll pair<ll,ll>
    #define pb(x) push_back(x)
    #define eb(x) emplace_back(x)
    #define mp(a,b) make_pair(a,b)
    #define ff first
    #define ss second  
    #define slld(x) scanf("%lld" , &x)
    #define sii(x) scanf("%d" , &x)
    #define sdoub(x) scanf("%lf" , &x)
     
    const int N = 1021;
     
    int dx[] = {0 , 0 , -1 , 1};
    int dy[] = {-1 , 1 , 0 , 0};
     
    bool is(ll x , ll y , ll rx , ll ry){
    	return !(x >= 1 and x < rx and y >= 1 and y < ry);
    }
     
    int main(){
    	#ifdef ABHI
    		freopen("input.txt" , "r" , stdin);
    	#endif
    	int t;
    	cin>>t;
    	FOR(tt,t){
    		ll n , m;
    		cin>>n>>m;
    		ll ar[n+1][m+1];
    		bool vis[n+1][m+1];
    		vector <pii> res[N+1];
    		FOR(i,n) FOR(j,m){
    			cin>>ar[i][j];
    			vis[i][j] = false;
    			if(ar[i][j] > 0){
    				res[ar[i][j]].push_back({i,j});
    			}
    		}
    		RFOR(i,N,0){
    			for(auto k : res[i]){
    				int x = k.ff;
    				int y = k.ss;
    				FOR(j,4){
    					int nx = x + dx[j] , ny = y + dy[j];
    					if(nx >= 0 and ny >= 0 and nx < n and ny < m and !vis[nx][ny] and !(ar[nx][ny] == -1)){
    						//cout<<nx<<" "<<ny<<endl;
    						vis[nx][ny] = true;
    						//assert(ny > m);// || ny < m || ny < 0 || nx < 0);
    						res[i-1].push_back({nx,ny});
    					}
    				} 
    			}
    		}
    		FORR(i,0,N){
    			for(auto k : res[i]){
    				vis[k.ff][k.ss] = true;
    			}
    		}
    		FOR(i,n){
    			FOR(j,m){
    				if(ar[i][j]==-1) cout<<"B";
    				else{
    					cout<<(vis[i][j]?"Y":"N");
    				}
    			}
    			cout<<endl;
    		}
    	}
    	#ifdef ABHI
    		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
    	#endif
    	return 0;
    }  
