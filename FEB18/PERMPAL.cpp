/*
 *	Abhishek(abhiy13)
 *	FEB18
 *	https://www.youtube.com/watch?v=r6zIGXun57U
*/
 
#include "bits/stdc++.h"
	using namespace std;
 
#define		io				std::ios::sync_with_stdio(false);
#define		FOR(i,n)		for(int i = 0 ; i < n ; i++)
#define		rep(i,a,b)		for(int i = a ; i < b ; i++)
#define 	rrep(i,a,b)		for(int i = a ; i > b ; i--)
#define 	timer			cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";	
 
typedef long long ll;
typedef unsigned long long llu;
const int maxchr = 1e6;
 
void isp(char* s , ll n){
	string kp[26];
	ll f[26];
	memset(f,0,sizeof(f));
	for(int i = 0 ; i < n ; i++){
		f[s[i]-'a']++;
		kp[s[i]-'a'] +=  to_string(i) + '#';
	}
	bool ok = true;
	ll cc = 0;
	char odd;
	for(int i = 0 ; i < 26 ; i++){
		if(f[i]&1) {
			odd = i + 'a';
			cc++;
		}
		if(cc>1) {ok = false;break;} 
	}
	if(!ok) {cout<<-1<<endl;return;}
	char t[n];
	ll k = 0;
	FOR(i,26){
		if((f[i]%2==0 && f[i]!=0)){
			ll count = ceil(f[i]/2);
			while(count>0){
				t[k] = i + 'a' ; t[n-k-1] = i + 'a';
				k++;
				count--;
			}
		}else if((f[i]%2==1 && f[i] > 2 && n%2==1)){
			ll count = ceil(f[i]/2);
			t[n/2] = i + 'a';
			while(count>0){
				t[k] = i + 'a' ; t[n-k-1] = i + 'a';
				k++;
				count--;
			}
		}
		else if(f[i]%2==1 && cc == 1 && n%2 == 1 && odd!=NULL) t[n/2] = odd;
	}
	ll ans[n];
	FOR(i,n){
		string kk = kp[t[i]-'a'];
		ll l=0;
		int j = 0;
		while(true){
			if(kk[j] == '#') {break;}
			l = l*10 + (kk[j]-'0');
			j++;
		}
		kp[t[i]-'a'].erase(kp[t[i]-'a'].begin(),kp[t[i]-'a'].begin()+j+1);
		ans[i] = (l+1);
	}
	FOR(i,n) cout<<ans[i]<<" ";
	cout<<endl;
}
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int t;
	cin>>t;
	FOR(tt,t){
		char s[maxchr];
		cin>>s;
		isp(s , strlen(s));
	}
	#ifdef ABHI
		timer
	#endif
	return 0;
} 
