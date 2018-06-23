#include "bits/stdc++.h"
	using namespace std;
 
#define PB(x) push_back(x)
#define EB(x) emplace_back(x)
#define F first
#define S second
 
#define TRACE
 
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
 
typedef long long ll;
typedef pair <int,int> pii;
typedef vector <int> vi;
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int n;
	cin>>n;
	string s[n] , ww;
	int tosz = 0;
	for(int i = 0 ; i < n ; i++) {cin>>s[i]; tosz += (int)s[i].length();}
	cin>>ww;
	unordered_map<char,ll> mp;
	for(auto &c : ww){
		mp[c]++;
	} 
	ll allowed = ww.length();
	if(allowed < tosz) {cout<<-1<<endl; return 0;}
	bool ok = true;int cnt = 0;
	for(int i = 0 ; i < n ; i++){
		for(char &c : s[i]){
			if(!mp[c]){
				cnt++;
				mp[c] = 1;
			}
			mp[c]--;
			allowed--;
			if(allowed < 0){
				ok = false;
				break;
			}
		}
		if(!ok) break;
	}
	if(!ok) cout<<-1<<endl;
	else cout<<cnt<<endl;
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
