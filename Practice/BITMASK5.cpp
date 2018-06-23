/******************************************
*  AUTHOR:         ABHISHEK YADAV         *
*  INSTITUITION:   CHANDIGARH UNIVERSITY  *
******************************************/
#include "bits/stdc++.h"
	using namespace std;
	
#define io std::ios::sync_with_stdio(false);cin.tie(NULL);
#define FOR(i,n) for(ll i = 0 ; i < n ; i++)
#define FORR(i,a,b) for(ll i = a ; i < b ; i++)
#define RFOR(i,a,b) for(ll i = a ; i > b ; i--)	
#define ll long long
#define llu unsigned long long
#define PB(x) push_back(x)
#define EB(x) emplace_back(x)
#define MP(a,b) make_pair(a,b)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define debug(x) cout<<x<<" ";
#define inf 1000000000000
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
 
template<typename T, typename U> inline void umin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void umax(T &x, U y) { if(x < y) x = y; }
 
 
 
//Using likecs and partial rajat1603 Lazy Propagation SegTree Template 		
 
const int LIM = 1000003; 
 
int segT[4*LIM];
int lazy[4*LIM];
 
void precalc(){
	memset(segT,0,sizeof(segT));
	memset(lazy,0,sizeof(lazy));
}
 
void propagate(int node , int l, int r) {
	if (lazy[node]) {
		if (l != r){
			int lc = node << 1;
			int rc = lc|1;
			lazy[lc] ^= 1;
			lazy[rc] ^= 1;
		}
		lazy[node] = 0;
		segT[node] = (r-l+1) - segT[node];
	}
}
 
void update(int l, int r, int index, int ql, int qr) {
	propagate(index,l,r);
	if (l > qr || r < ql) {
		return;
	}
	if (ql <= l && qr >= r) {
		lazy[index] = 1;
		propagate(index, l, r);
		return;
	}
	int lc = index<<1;
	int rc = lc|1;
	int mid = (l+r)>>1;
	update(l, mid,lc ,ql, qr);
	update(mid + 1, r, rc ,ql, qr);
	segT[index] = segT[lc] + segT[rc];
}
 
int query(int l, int r, int index, int ql, int qr) {
	propagate(index,l,r);
	if (l > qr || ql > r){
		return 0;
	}
	if (ql <= l && r <= qr){
		return segT[index];
	}
	int mid = (l+r)>>1;
	int lc = index << 1;
	int rc = lc|1;
	return query(l,mid,lc,ql,qr)+query(mid+1,r,rc,ql,qr);
}
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	precalc();
	int n , q;
	cin>>n>>q;
	int t , x , y;
	while(q--){
		cin>>t>>x>>y;
		if(t==0){
			update(0,n-1,1,x,y);
		}else{
			cout<<query(0,n-1,1,x,y)<<endl;
		}
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
