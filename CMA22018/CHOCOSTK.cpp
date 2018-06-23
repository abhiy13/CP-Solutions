/******************************************
*  AUTHOR:         ABHISHEK YADAV         *
*  INSTITUITION:   CHANDIGARH UNIVERSITY  *
******************************************/
#include "bits/stdc++.h"
	using namespace std;
	
#define io std::ios::sync_with_stdio(false);cin.tie(NULL);
#define FOR(i,n) for(ll i = 0 ; i < n ; i++)
#define FORR(i,a,b) for(ll i = a ; i < b ; i++)
#define RFOR(i,a,b) for(ll i = a ; i > b ; i--)	
#define ll long long
#define llu unsigned long long
#define PB(x) push_back(x)
#define EB(x) emplace_back(x)
#define MP(a,b) make_pair(a,b)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define debug(x) cout<<x<<" ";
#define inf 1000000000000
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
 
template<typename T, typename U> inline void umin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void umax(T &x, U y) { if(x < y) x = y; }
 
 
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int t;
	cin>>t;
	FOR(tt,t){
		ll n;
		cin>>n;
		ll asd;
		ll mof  = 0 , mos  = 0 , ots = 0;
		FOR(i,n){
			cin>>asd;
			if(asd%7==0){
				//mos.PB(asd);
				mos += asd;
			}else if(asd%5 == 0){
				//mof.PB(asd);
				mof += asd;
			}else{
				//ots.PB(asd);
				ots += asd;
			}
		}
		ll dif = abs(mof - mos);
		if(dif == 0 and (mof != 0 and mos != 0)) cout<<"true\n";
		else if(dif == ots) cout<<"true\n";
		else if(dif > ots) cout<<"false\n";
		else{	
			if(mof < mos){
				mof = mos;
				ots = dif;
			}else if(mos < mof){
				mos = mof;
				ots = dif;
			}
			if(ots&1) cout<<"false\n";
			else cout<<"true\n"; 
		} 		
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
