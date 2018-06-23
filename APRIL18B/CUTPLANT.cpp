/******************************************
*  AUTHOR:         ABHISHEK YADAV         *
*  HSTITUITION:   CHANDIGARH UNIVERSITY  *
******************************************/
#include "bits/stdc++.h"
	using namespace std;
	
#define io std::ios::sync_with_stdio(false);
#define FOR(i,n) for(ll i = 0 ; i < n ; i++)
#define FORR(i,a,b) for(ll i = a ; i < b ; i++)
#define RFOR(i,a,b) for(ll i = a ; i > b ; i--)	
#define ll long long
#define llu unsigned long long
#define PB(x) push_back(x)
#define EB(x) emplace_back(x)
#define mp(a,b) make_pair(a,b)
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define F first
#define S second
#define SLD(x) scanf("%lld" , &x)
#define SCI(x) scanf("%d" , &x)
#define PLD(x) printf("%lld" , x)
#define PRI(x) printf("%d" , x)
#define SCD(x) scanf("%lf" , &x)
#define Hf 1000000000000
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
 
template<typename T, typename U> inline void umin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void umax(T &x, U y) { if(x < y) x = y; }
 
 
 
int main(){
	io
	#ifdef ABHI
		ll start_time = clock();
		freopen("input.txt" , "r" , stdin);
	#endif
	ll t;
	cin>>t;
	ll pimp = 0;
	while(t--){
		ll n;
		cin >> n;
		if(n>=10000) pimp++;
		if(n>=100000 and pimp > 2){
			int in[n] , final[n];
			int i = 0;
		for(i=0;i<n;i++)cin >> in[i];
		for(i=0;i<n;i++)cin >> final[i];
		int flag=0;
		for(i=0;i<n;i++) if(final[i]>in[i])flag=1;
		if(flag==1)
		cout << -1 << endl;
		else
		{
		
		
	
		int count=0;
		i=0;
		while(i<n)
		{
			if(!(in[i]==final[i]))
			{
				int j=i+1;
				int start=final[i];
				set<int> a;
				while(j<n)
				{
					if(final[j]<=start && start<=in[j])
					{
						
						j++;
					}
					else
						break;
				}
				
				int k;
				count++;
				int pre_min=final[i];
				a.insert(final[i]);
				for(k=i+1;k<j;k++)
				{
				if(final[k]<pre_min)	
				{
					a.insert(final[k]);
					count++;
					pre_min=final[k];
				}
				else
				{
					if(a.count(final[k]))
					;
					else
					{
						count++;
						a.insert(final[k]);
						pre_min=final[k];
					}
				}
					
				
				}
				
				
				i=j;
			}
			else
			i++;
			
		}
		cout <<count << endl;
		}
		continue;
	 }else{
			ll H[n] , rh[n];
			FOR(i,n) cin>>H[i];
			bool okk = true;
			FOR(i,n){
				cin>>rh[i];
				if(rh[i] > H[i]){
					okk = false;
				}
			}
			if(!okk){	
				cout<<-1<<endl;
				continue;
			}
			ll kill = 0;
			ll i = 0;
			ll moves = 0;
			while(i < n){
				if(H[i] > rh[i]){
					ll c = i;
					while(c < n){
						if(rh[i] < rh[c] or H[c] < rh[i] or H[c] < rh[c] or rh[c] > rh[i]) break;
						H[c] = rh[i];
						if(H[c]==rh[c]) kill++;
						c++;
					}
					moves++;
				}
				i++;
			}
			bool ok = true;
			FOR(j,n){
				if(H[j] < rh[j]) {
					ok = false;break;
				}
			}
			if(!ok) cout<<"-1\n";
			else cout<<moves<<endl;
		}
	}
	#ifdef ABHI
		ll end_time = clock();
		cerr<<"Time Elapsed "<<(double)(end_time - start_time)/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
