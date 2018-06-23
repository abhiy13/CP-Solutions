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
#define VAL 1005
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
int t;
	cin>>t;
	FOR(tt,t){
		ll n;
		string s;
		cin>>s>>n;
		if(n <= 1000){
			string k = s;
			FOR(i,n-1) s += k;
			ll counta = 0 , countb = 0;
			ll res = 0;
			FOR(i,(ll)s.size()){
				counta += ((s[i]=='a')?1:0);
				countb += ((s[i]=='b')?1:0);
				if(counta > countb) res++;
			}
			cout<<res<<endl;
			continue;
		}
		ll a[VAL],b[VAL],c[VAL] , res = 0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		ll nn = (ll)s.length();
		for(int i = nn-1 ; i >= 0 ; --i){
			if(s[i]=='a') a[i]++;
			if(s[i]=='b') b[i]++;
			a[i]+=a[i+1];
			b[i]+=b[i+1];
			c[i]=a[i]-b[i];
		}
		ll e = c[0];
		for(int i = 0 ; i < nn ; ++i){
		 	ll kk=a[i+1]-b[i+1];;
			ll tp;
			if(e==0){
				if(kk<0) res += n;
			}else if(e>0){
				tp=abs(kk)/abs(e);
				if(kk<=0) res+=n;
				else 
				res+=max(0LL,n-tp);
			}else{
				tp=abs(kk)/abs(e);
				if(kk<0){
					if(abs(kk)%e)
						res+=max(0LL,tp);
					else
						res+=max(0LL,tp-1);
				}
			}
		}
		cout<<res<<endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
