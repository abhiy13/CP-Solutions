/******************************************
*  AUTHOR:         ABHISHEK YADAV         *
*  INSTITUITION:   CHANDIGARH UNIVERSITY  *
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
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define SLD(x) scanf("%lld" , &x)
#define SCI(x) scanf("%d" , &x)
#define PLD(x) printf("%lld" , x)
#define PRI(x) printf("%d" , x)
#define SCD(x) scanf("%lf" , &x)
#define inf 1000000000000
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
 
template<typename T, typename U> inline void umin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void umax(T &x, U y) { if(x < y) x = y; }
 
 
 
int main(){
	#ifdef ABHI
		ll start_time = clock();
		freopen("input.txt" , "r" , stdin);
	#endif
	string s[] = {"regression", "clustering", "trees", "bayesian","regression.", "clustering.", "trees.", "bayesian."};
	map <string,bool> mp;
	FOR(i,8) mp[s[i]] = true;
	ll count=0 , cp=0;string ss;
	while(cin>>ss){
		string z = ss;
		transform(z.begin(),z.end(),ss.begin(),::tolower);
		if(mp[ss]) count++;
		cp++;
	}
	if(count != 0){
		ll q = __gcd(count,cp);
		count /= q;
		cp /= q;
	}
	cout<<count<<"/"<<cp<<endl;
	#ifdef ABHI
		ll end_time = clock();
		cerr<<"Time Elapsed "<<(double)(end_time - start_time)/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
