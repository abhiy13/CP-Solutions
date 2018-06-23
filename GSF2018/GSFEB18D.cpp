/*
 *	Abhishek(abhiy13)
 *	Chandigarh University
*/
 
#include "bits/stdc++.h"
	using namespace std;
 
#define io std::ios::sync_with_stdio(false);
#define FOR(i,n) for(int i = 0 ; i < n ; i++)
#define rep(i,a,b) for(int i = a ; i < b ; i++)
#define rrep(i,a,b) for(int i = a ; i > b ; i--)
#define timer cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";	
 
typedef long long ll;
typedef unsigned long long llu;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const int mod = 1e9+7;
 
bool isV(char c){
     if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return true;
     return false;
}
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int t;
	cin>>t;
	while(t--){
	     int n;
	     cin>>n;
	     string s1 , s2;
	     ll ss=0, sss=0;
	     while(n--){
	          int o=0 , to=0;
	         cin>>s1>>s2;
	         FOR(i,s1.size()) if(isV(s1[i])) o++;
	         FOR(i,s2.size()) if(isV(s2[i])) to++;
	         if(o==to) ss++;
	         else sss++;
	     }
	     if(ss>=sss) cout<<"jane\n";
	     else cout<<"secretbff\n";
	}
	#ifdef ABHI
		timer
	#endif
	return 0;
} 
