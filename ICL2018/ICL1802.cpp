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
#define all(x) begin(x),end(x)
 
typedef long long ll;
typedef unsigned long long llu;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const int mod = 1e9+7;
 
	
int gcd(int a,int b){
	if(b==0)
		return a;
 	return gcd(b,a%b); 
}
 
int main(){
 	//freopen("input.txt" , "r" , stdin);
	int t;
	cin>>t;
	while(t--){ 
		int n,k;
		cin>>n>>k;
		string str;
		cin>>str;
		int count=0;
		int sum=0;
		sort(str.rbegin(),str.rend());
		for(int i=0;i<n;i++){
			if((str[i]-'a'+1) >= k*2){
				sum = sum + (str[i]-'a'+1);
				count++;
			}
			else{
				break;
			}
		}
		int ans = ((n-(2*count))*k) + sum;
		int ress = gcd(ans,k);
		int a = ans/ress;
		int b = k/ress;
		printf("%d %d\n",a,b);
	 
	}
	return 0;
}
 
 
