/******************************************
*  AUTHOR:         ABHISHEK YADAV         *
*  INSTITUITION:   CHANDIGARH UNIVERSITY  *
******************************************/
#include "bits/stdc++.h"
	using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> pll;
 
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int T;
	cin>>T;
	while(T--){
		ll n , k;
		cin>>n>>k;
		vector <pll> v(n);
		for(int i = 0 ; i < n ; i++) cin>>v[i].first;
		ll tc = 0;
		for(int i = 0 ; i < n ; i++) {cin>>v[i].second;tc += v[i].second;}
		sort(v.begin(), v.end());
		ll x = 0;
		ll p = tc-x , start = 0 , end = n-1;
		for(int game = 1 ; game <= k ; game++){
			cin>>x;
			p = tc-x;
			tc -= p;
			if(game&1){ //if x is odd , this is equivalet to x%2 == 1
				ll i = start;
				while(1){
					if(v[i].second < p){
						p -= v[i].second;
						v[i].second = 0;
						i++;
					}else{
						v[i].second -= p;
						p = 0;
						if(v[i].second == 0) start = i+1;
						else start = i;
						break;
					}
				}
			}else{
				ll i = end;
				while(1){
					if(v[i].second < p){
						p -= v[i].second;
						v[i].second = 0;
						i--;
					}else{
						v[i].second -= p;
						p = 0;
						if(v[i].second == 0) end = i-1;
						else end = i;
						break;
					}
				}
			}
		}
		ll res = 0;
		for(int i = 0 ; i < n ; i++) res += v[i].first*v[i].second;
		cout<<res<<endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
