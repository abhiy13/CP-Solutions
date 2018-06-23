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
	ll n;
	cin>>n;
	string s;
	cin>>s;
	ll ii = 0;
	while(s[ii]=='0') ii++;
	for(auto &c : s){
		if(c != '4' and c!='7' and c!= '0'){
			cout<<"NO\n";
			return 0;
		}
	}
	ll mid = 0 , res1 = 0 , res2 = 0;
	n -= ii;
	mid = n/2;
	FORR(i,ii,mid+ii) {res1 += s[i] - '0';}
	FORR(i,mid+ii,n+ii) res2 += s[i] - '0';
	cout<<((res1==res2)?"YES\n":"NO\n");
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
}
 
