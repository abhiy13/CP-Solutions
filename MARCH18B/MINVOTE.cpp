/*
 *	Abhishek(abhiy13)
 *	MARCH18
 * 	https://www.youtube.com/watch?v=r6zIGXun57U
*/
 
#include "bits/stdc++.h"
	using namespace std;
 
#define	io				std::ios::sync_with_stdio(false);
#define	FOR(i,n)		for(ll i = 0 ; i < n ; i++)
#define	FORR(i,a,b)		for(ll i = a ; i < b ; i++)
#define RFOR(i,a,b)		for(ll i = a ; i > b ; i--)
#define timer			cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";	
#define all(x)			begin(x),end(x)
#define SZ(x) x.size()
#define shell cout<<endl;
 
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> ar(n+1) , prefix(n+1) , ans(n+1) , temp(n+1);
		//fill(all(ans),0);
		//fill(all(temp),0);
		prefix[0] = 0 , temp[n] = 1;
		FORR(i,1,n+1){
			cin>>ar[i];
			prefix[i] += ar[i] + prefix[i-1];
			//cout<<prefix[i+1]<<endl;
		}
		ll l , h , mid;
		FORR(i,1,n+1){
			// A type of binary Search Mechanism :)
			l = 1 , h = i , mid = 0;
			// for the starting part of the array :()
			while(l<h){
				mid  = (l + h) >> 1;
				if((prefix[i-1] - prefix[mid]) > ar[i]) l= mid+1;
				else h = mid;
				//cout<<l<<" "<<h<<" "<<mid<<endl;
			}
			ans[l]++;
			if(i==n){
				break;
			}
			// reverse and get the rest of the answer :) (I mean Later Paer ;) )
			l = i , h = n;
			while(l<h){
				mid = (l + h + 1) >> 1;
				if((prefix[mid-1] - prefix[i]) > ar[i]) h= mid-1;
				else l = mid;
				//cout<<l<<" "<<h<<" "<<mid<<endl;
			} 
			temp[l]++;
		}
		ll res = 0 ;//= ans[1] - 1;
		FORR(i,1,n+1){
			res += ans[i];
			cout<<res-1<<" ";
			res -= temp[i];
		}
		shell
	}
	#ifdef ABHI
		timer
	#endif
	return 0;
} 
