/******************************************
*  AUTHOR:         ABHISHEK YADAV         *
*  INSTITUITION:   CHANDIGARH UNIVERSITY  *
******************************************/
#include "bits/stdc++.h"
	using namespace std;
 
typedef long long ll;
 
void decrypt(string &s, ll x, ll d){
    string res;
    ll rem;
    for(int i=0 ; i < (int)s.length() ; i++){
        rem = ( (s[i]-'a') - (i*d + x) )%26;
        rem = rem<0 ? (26+rem) : rem;
        res += (char)('a'+rem);
    }
    s =  res;
}
 
void solve(string s){
	ll ar[26] = {0};
	for(char &c : s){
		ar[c-'a']++;
	}
	ll res = 0;
	int mid = 0;
	for(int i = 0 ; i < 26 ; i++){
		if(ar[i]&1){
			res += (ar[i]-1);
			mid = 1;
		}else{
			res += ar[i];
		}
	}
	res += mid;
	cout<<res<<endl;
}
 
int main(){
	ios::sync_with_stdio(false);
	ll x , d;
	cin>>x>>d;
	string s;cin>>s;
	decrypt(s,x,d);
	solve(s);
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
