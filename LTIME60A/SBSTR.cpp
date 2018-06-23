#include "bits/stdc++.h"
	using namespace std;
typedef long long ll;
 
string str;
ll k;
 
bool isok(ll strt,ll ed,ll ar[]){
	ll ct=0, idx=-1;
	for(int i=0;i<26;i++){
		if(ar[i]!=0){
			if(idx == -1)
			idx=i;
			else{
				if(ar[idx]!=ar[i])
				return false;
			}
			ct++;
		}
	}
	if(ct<k)
		return false;
	return true;
}
int main() {
	ll t;
	cin>>t;
	while(t--){
		cin>>str>>k;
		ll n = str.length() , res = 0;
		for(ll i=0;i<n;i++){
			ll ar[26]={0};
			for(ll j=i;j<n;j++){
				ar[str[j]-'a']++;
				if(isok(i,j,ar)){
					res++;
				}
			}
		}
		cout<<res<<endl;
	}
	return 0;
} 
