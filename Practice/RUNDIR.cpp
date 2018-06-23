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
#define ld long double
#define pii pair <int,int>
#define pll pair <int,int> 
#define vi vector <int>
 
 
bool solvable(const double &mid , vector <pll> &v){
	vector <bool> directions((ll)v.size(),false);
	for(int i = 1 ;  i < (ll)v.size() ; i++){
		if(directions[i-1]){
			if(mid*(v[i].S + v[i-1].S) >= (v[i].F - v[i-1].F)){
				if(mid*v[i].second + v[i].first <= mid*v[i-1].second + v[i-1].first){
					return false;
				}
				directions[i] = true;
			}
		}else{
			if(v[i].F - mid*v[i].S <= v[i-1].F - mid*v[i-1].S){
				directions[i] = true;
			}
		}
	}
	return true;
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(7);
	cout<< fixed;
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int T;
	cin>>T;
	while(T--){
		ll n;
		cin>>n;
		vector <pll> v(n,{0,0});	
		FOR(i,n) cin>>v[i].F>>v[i].S;
		sort(v.begin(), v.end());
		ld lo  = 0 , hi = 1e20 , mid;
		for(int i = 0 ;i < 100 ; i++){
			mid = (lo+hi)*0.5;
			if(solvable(mid,v)){
				lo = mid;
			}else{
				hi = mid;
			}
		}
		if(mid > 1e15) cout<<"-1\n";
		else cout<<mid<<endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
}
 
