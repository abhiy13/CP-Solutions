/*
 *	Abhishek(abhiy13)
 *	FEB18
 * 	https://www.youtube.com/watch?v=r6zIGXun57U
*/
 
#include "bits/stdc++.h"
	using namespace std;
 
#define		io				std::ios::sync_with_stdio(false);
#define		FOR(i,n)		for(int i = 0 ; i < n ; i++)
#define		rep(i,a,b)		for(int i = a ; i < b ; i++)
#define 	rrep(i,a,b)		for(int i = a ; i > b ; i--)
#define 	timer			cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";	
#define 	all(x)			(x.begin(),x.end())
#define 	SZ(x)			(x.size())
#define 	pi 			vector<pair<ll,ll>>
 
typedef long long ll;
typedef unsigned long long llu;
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int t;
	cin>>t;
	FOR(tt,t){
		int n;
		cin>>n;
		pi seg(n);
		FOR(i,n) cin>>seg[i].first>>seg[i].second;
		int q;
		cin>>q;
		while(q--){
			int res=0;
			int nn;
			cin>>nn;
			int points[nn];
			sort(points, points+nn);
			FOR(i,nn) cin>>points[i];
			FOR(i,n){
				int res1=0;
				FOR(j,nn){
					if(points[j]>=seg[i].first && points[j]<=seg[i].second) res1++;
					if(points[j]>seg[i].second) break;
				}
				if(res1&1) res++;
			}
			cout<<res<<endl;
		}
	}
	#ifdef ABHI
		timer
	#endif
	return 0;
} 
