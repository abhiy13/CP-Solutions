#include <bits/stdc++.h>
	using namespace std;
 
struct node{
	int a , b , c , d;
	node(int a_ = 0 , int b_ = 0 , int c_ = 0 , int d_ = 0) : a(a_) , b(b_) , c(c_) , d(d_) {}
};
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int n;
	cin >> n;
	vector < node > v(n);
	for(int i = 0 ; i < n ; i++){
  	cin >> v[i].a >> v[i].b >> v[i].c;
  	v[i].d = v[i].b + v[i].c;
	}
	sort(v.begin(), v.end() , [&](node &a , node &b){
		return a.d > b.d;
	});
	int dp[n][2] , res = -1;
	dp[0][0] = v[0].d;
	dp[0][1] = v[0].a;
	for(int i = 1 ; i < n ; i++){
		dp[i][0] = dp[i-1][1] + v[i].d + v[i].a;
		dp[i][1] = dp[i-1][1] + v[i].a;
		res = max( res , dp[i][0] );
	}
	cout << res << '\n';
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
}
 
