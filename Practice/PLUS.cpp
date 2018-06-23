#include "bits/stdc++.h"
	using namespace std;
 
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int T;
	cin>>T;
	while(T--){
		int n , m;
		cin>>n>>m;
		vector < vector <int> > ar(n , vector<int>(m));
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < m ; j++)
				cin>>ar[i][j];
		vector < vector <int> > U(n , vector<int>(m));
		vector < vector <int> > D(n , vector<int>(m));
		vector < vector <int> > L(n , vector<int>(m));
		vector < vector <int> > R(n , vector<int>(m));
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				U[i][j] = ((i==0 || U[i-1][j]<=0)?0:U[i-1][j]) + ar[i][j];
				L[i][j] = ((j==0 || L[i][j-1]<=0)?0:L[i][j-1]) + ar[i][j];
			}
		}
		for(int i = n-1 ; i >= 0 ; i--){
			for(int j = m-1 ; j >= 0 ; j--){
				D[i][j] = ((i==n-1 || D[i+1][j]<=0)?0:D[i+1][j]) + ar[i][j];
				R[i][j] = ((j==m-1 || R[i][j+1]<=0)?0:R[i][j+1]) + ar[i][j];
			}
		}
		int ans = -(int) 2.1e9;
		for(int i = 1 ; i < n-1 ; i++){
			for(int j = 1 ; j < m-1 ; j++){
				ans = max(ans , ar[i][j] + U[i-1][j] + L[i][j-1] + R[i][j+1] + D[i+1][j]);
			}
		}
		cout<<ans<<endl;
	}	
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
