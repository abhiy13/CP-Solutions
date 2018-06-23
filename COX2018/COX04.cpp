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
 
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	ll n , m;
	cin>>n>>m;
	string s[n];
	FOR(i,n) cin>>s[i];
	bool ok = true;
	unordered_map<char , bool> mp;
	FOR(i,n){
		if(mp[s[i][0]]){
			ok = false;
			break;
		}
		FOR(j,m){
			if(s[i][j] != s[i][0]){
				ok = false;
				break;
			}
		}
		mp[s[i][0]] = true;
		if(!ok) break;
	}
	if(ok) cout<<"YES\n";
	else cout<<"NO\n";
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
}
 
