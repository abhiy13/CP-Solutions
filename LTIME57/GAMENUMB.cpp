/*
 *	Abhishek(abhiy13)
 *	Chandigarh University
*/
 
#include "bits/stdc++.h"
	using namespace std;
 
#define io std::ios::sync_with_stdio(false);
#define FOR(i,n) for(int i = 0 ; i < n ; i++)
#define FORR(i,a,b) for(int i = a ; i < b ; i++)
#define rrep(i,a,b) for(int i = a ; i > b ; i--)
#define timer cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
#define all(x) begin(x),end(x)
 
typedef long long ll;
typedef unsigned long long llu;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const int mod = 1e9+7;
 
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	ll t;	
	cin >> t;
	while(t--){
	     ll n , k;
	     map<ll,ll> mp;
		cin >> n >> k;
		ll a[n],d[n],b=0,s=0,c1=0,c2=n;
	     FOR(i,n) cin >> a[i];
		FOR(i,n){
			cin >> d[i];
			mp[a[i]] += d[i];
			s += d[i];
		}
		sort(a,a+n);
		//s = n;
		//cout<<s<<endl;
		FORR(i,1,k+1){
			cin >> b;
			if(i&1){
				while((s-b)>0){
					if(mp[a[c1]]>(s-b)) {mp[a[c1]]-=(s-b); s=b;}
					else {s-=mp[a[c1]];	mp[a[c1]]=0; c1++;}
				}
			}
			else if(i%2==0({
				while((s-b)>0){
					if(mp[a[c2]]>(s-b)) {mp[a[c2]]-=(s-b); s=b;}
					else {s -= mp[a[c2]] ; mp[a[c2]]=0; c2--;}
				}
			}
		}
		ll ans1=0,ans2=0;
		for(ll i=c1;i<=c2;i++){
			ans2 += a[i]*mp[a[i]];
		}
		cout<<ans2<<endl;
	}
	#ifdef ABHI
		timer
	#endif
	return 0;
} 
