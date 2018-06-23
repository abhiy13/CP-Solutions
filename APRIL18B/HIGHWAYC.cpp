#include "bits/stdc++.h"
	using namespace std;
 
#define io std::ios::sync_with_stdio(false);
#define FOR(i,n) for(ll i = 0 ; i < n ; i++)
#define FORR(i,a,b) for(ll i = a ; i < b ; i++)
#define RFOR(i,a,b) for(ll i = a ; i > b ; i--)	
#define ll long long
#define llu unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second  
#define slld(x) scanf("%lld" , &x)
#define sii(x) scanf("%d" , &x)
#define sdoub(x) scanf("%lf" , &x)
 
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int T, N, S, Y;
	cin >> T;
	while(T--) {
		cin >> N >> S >> Y;
		int V[N], P[N], C[N];
		bool D[N];
		double ans = 0, cpos, cposend ,cpos2, cposend2, wtime, cheftime;
		for(int i = 0; i < N; i++)
			cin >> V[i];
		for(int i = 0; i < N; i++)
			cin >> D[i];
		for(int i = 0; i < N; i++)
			cin >> P[i];
		for(int i = 0; i < N; i++)
			cin >> C[i];
		cheftime = ((double) Y)/S;
		for(int i = 0; i < N; i++) {
			cpos = ans*(V[i]*(D[i] ? 1 : -1)) + P[i];
			cposend = cpos - (C[i]*(D[i] ? 1 : -1));
			cpos2 = cpos + cheftime*(V[i]*(D[i] ? 1 : -1));
			cposend2 = cposend + cheftime*(V[i]*(D[i] ? 1 : -1));
			wtime = 0;
			if(cpos*cposend < 0 || cpos*cpos2 < 0 || fabs(cpos2) < .000001 || fabs(cpos) < .000001)
				wtime = fabs(cposend+.000001)/V[i];
			ans = ans + wtime + cheftime;
		}
 
		cout << fixed << setprecision(10) << ans << endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
}  
