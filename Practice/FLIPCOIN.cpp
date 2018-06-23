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
 
#define N 100001
 
int segtree[4*N];
int lazy[4*N];
 
void precalc(){
	memset(segtree,0,sizeof(segtree));
	memset(lazy,0,sizeof(lazy));
}
 
void propagate(int l , int r , int index){
	if(lazy[index]){
		if(l!=r){
			int lc = index<<1;
			int rc = lc|1;
			lazy[lc] ^= 1;
			lazy[rc] ^= 1;
		}
		lazy[index] = 0;
		segtree[index] = (r-l+1)-segtree[index];
	}
}
 
void update(int l , int r , int index , int ql , int qr){
	propagate(l,r,index);
	if(l > qr or r < ql) return;
	if(ql <= l and qr >= r){
		lazy[index] = 1;
		propagate(l,r,index);
		return;
	}
	int lc = index<<1;
	int rc = lc|1;
	int mid = (l+r)>>1;
	update(l,mid,lc,ql,qr);
	update(mid+1,r,rc,ql,qr);
	segtree[index] = segtree[lc]+segtree[rc];
}
 
int query(int l , int r , int index , int ql , int qr){
	propagate(l,r,index);
	if(l > qr or ql > r) return 0;
	if(l >= ql and r <= qr){
		return segtree[index];
	}
	int lc = index<<1;
	int rc = lc|1;
	int mid = (l+r)>>1;
	return query(l,mid,lc,ql,qr)+query(mid+1,r,rc,ql,qr);
}
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int n , t;
	cin>>n>>t;
	precalc();
	int l , r , f;
	FOR(tt,t){
		cin>>f>>l>>r;
		if(f){
			cout<<query(0,n-1,1,l,r)<<endl;
		}else{
			update(0,n-1,1,l,r);
		}
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
