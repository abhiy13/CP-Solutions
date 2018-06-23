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
 
#define inf 0000000000
 
//Using Inclusion exclusion principle 
// This type of 2D dp problems are present a lot on SPOJ
// Previous Submission forgot to add reference link 
// Problem reference : http://www.spoj.com/problems/ACTIV/
// submission of code reference : Submission ID: 21568199
// Partially taken from Quora for the above question
// Works on same exclusion and inclusion principal
 
void solve(ll ar[] , ll n){
	if(ar[1] > ar[0]){
		ar[0] *= -1;
	}
	FORR(i,1,n-1){
		if(ar[i] < ar[i-1] and ar[i] < ar[i+1]){
			ar[i] *= -1;
		}
	}
	if(ar[n-1] < ar[n-2]) ar[n-1] *= -1;
	vector <ll> set_T , pos;
	ll i = 0;
	while(i<n){
		if(ar[i]<0){
			set_T.push_back(ar[i]);
			pos.push_back(i);
			i++;
		}else{
			ll sum=0;
			while(ar[i]>0 && i<n){
				sum+=ar[i];
				i++;
			}
			set_T.push_back(sum);
			pos.push_back(-1);
		}	
	}
	ll ns = set_T.size();
	ll dP[2][ns];
	if(set_T[0] < 0){
		dP[0][0] = set_T[0]*-1;
		dP[1][0] = set_T[0];
	}else{
		dP[0][0] = dP[0][1] = set_T[0];
	}
	if(set_T[1] > 0){
		dP[0][1] = dP[0][0] + set_T[1];
		dP[1][1] = dP[1][0] + set_T[1];
	}else{
		dP[0][1]=min(dP[0][0],dP[1][0]) + set_T[1]*-1;
		dP[1][1]=min(dP[0][0],dP[1][0]) + set_T[1];
	}
	ll vis[ns] , ispossible[ns];
	FOR(i,ns){
		vis[i] = ispossible[i] = 1;
	}
	FORR(i,2,ns){
		if(set_T[i] > 0){
			dP[0][i]=dP[0][i-1]+set_T[i];
			dP[1][i]=dP[1][i-1]+set_T[i];
		}else{
			dP[0][i]=min(dP[0][i-1],dP[1][i-1]) +set_T[i]*-1;
			if(set_T[i-2]+set_T[i-1]+set_T[i] >0)
				dP[1][i]=min(dP[0][i-1],dP[1][i-1]) + set_T[i];
			else{
				ispossible[i]=0;
				dP[1][i]=dP[0][i-1] + set_T[i];
			}
		}
	}
	ll idx = 0;
	if(dP[1][ns-1] < dP[0][ns-1]){
		idx = 1;
	}else{
		idx = 0;
	}
	RFOR(i,ns-1,0){
		if(set_T[i] < 0){
			if(idx==0){
				vis[i]=-1;
				if(dP[1][i-1]<dP[0][i-1])
					idx=1;
				else
					idx=0;
			}else{
				if(ispossible[i]==0) idx = 0;
				else{
					if(dP[1][i-1] < dP[0][i-1]) idx = 1;
					else idx = 0;
				}
			}
		}
	}
	if(set_T[0] < 0){
		if(idx == 0) vis[0] = -1;
	}
	FOR(i,ns){
		if(vis[i]==-1){
			ar[pos[i]] *= -1;
		}
	}
	FOR(i,n) cout<<ar[i]<<" ";
}
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int T;
	cin>>T;
	while(T--){
		ll n ; cin>>n;
		ll ar[n];
		FOR(i,n) cin>>ar[i];
		solve(ar,n);
		cout<<endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
}
 
