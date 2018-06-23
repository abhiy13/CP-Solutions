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
#define pll pair <int,int> 
#define vi vector <int>
 
inline ll maxE(ll a , ll b){
	return (a > b) ? a : b;
}
 
ll search(ll a[] , ll n , ll x , ll idx, ll p1){
	ll lo = 0 , hi = n-1 , count = 0 , max = 0 , maxA = 0, maxB = 0 , countA = 0 , countB = 0;
   	while (lo <= hi) {
   		ll mid = (lo+hi)>>1;
   	   	if (mid == idx){
      		break;
		}else if(mid < idx){
			lo = mid + 1;
			if(a[mid] > x){
				countB++;
			}
			maxB++;
	    }else{
		  	hi = mid - 1;
			if(a[mid] < x){
				countA++;
			}
			maxA++;
		}
   	}
   	if(p1 < maxB or maxA > (n-1-p1)) return -1;
   	return maxE(countA , countB);
}
 
inline ll binary_search(ll ar[] , ll x , ll n){
	ll lo = 1 , hi = n;
	while(lo <= hi){
		ll mid = (lo+hi)>>1;
		if(ar[mid] == x) return mid;
		if(ar[mid] < x) lo = mid + 1;
		else hi = mid - 1;
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int T;
	cin>>T;
	while(T--){
		ll n,q;
		cin>>n>>q;
		ll ar[n+1] , br[n];
		unordered_map <ll,ll> pos , lT , gT;
		FOR(i,n){
			cin>>ar[i];
			br[i] = ar[i];
			pos[ar[i]] = i;
		}
		sort(br,br+n);
		ll qq;
		while(q--){	
			cin>>qq;
			ll p1 = lower_bound(br,br+n,qq) - br;
			ll res = search(ar,n,qq,pos[qq],p1);
      		cout<<res<<endl;
		}
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
}
  
