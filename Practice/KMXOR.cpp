#include "bits/stdc++.h"
	using namespace std;
 
 
#define PB(x) push_back(x)
#define EB(x) emplace_back(x)
#define F first
#define S second
#define FOR(i,n) for(ll i = 0 ; i < n ; i++)
#define FORR(i,a,b) for(ll i = (ll)a ; i < (ll)b ; i++)
#define RFOR(i,a,b) for(ll i = (ll)a ; i > (ll)b ; i--)
#define ll long long
#define llu unsigned long long
#define pii pair <int,int>
#define pll pair <ll,ll> 
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int T;
	cin>>T;
	while(T--){
		ll n , k;
		cin>>k>>n;
		if(n == 1){
			FOR(i,k) cout<<"1 ";
			cout<<endl;
		}else if(k == 1){
			cout<<n<<endl;
		}else if(k%2==0){
			FOR(i,k-2) cout<<"1 ";
			ll m = log2(n);
			ll res = (1<<m);
			cout<<res<<" "<<res-1<<endl;
		}else{
			if(n==3){
				cout<<"3 ";
				FOR(i,k-1) cout<<"1 ";
				cout<<endl;
			}else if(n == 2){
				cout<<"2 ";
				FOR(i,k-1) cout<<"1 ";  
			}else{
				ll m = log2(n);
				ll f1 = 1<<m , f2 = 1<<(m-1);
				cout<<f1<<" "<<f2<<" "<<f2-1<<" ";
				FOR(i,k-3) cout<<"1 ";
				cout<<endl;
			}
		}
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
}
 
