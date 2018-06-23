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
#define SLLD(x) scanf("%lld" , &x)
#define PLLD(x) printf("%lld\n" , x)	
 
#define N 20099
ll BLOCK; // ~sqrt(N)
 
ll ar[N] , BIT[N] , res[N] ,ans = 0; 
map <ll,ll> mp;
ll n;
 
struct query{
	ll L , R, pos;
	query(){
		L =0 , R = 0 , pos = 0;
	}
}qq[N];
 
ll sum(ll idx){
	ll sum = 0;
	while(idx > 0){
		sum += BIT[idx]; 
		idx -= (idx&(-idx));
	}
	return sum;
}
 
void update(ll idx ,ll val){
	while(idx <= n + 10){
		BIT[idx] += val;
		idx += (idx&(-idx));
	}
}
 
 
void add_l(ll idx){
	ans += sum(ar[idx]-1);
	update(ar[idx] ,1);
}
 
void add_r(ll idx){
	ans += sum(n+5) - sum(ar[idx]);
	update(ar[idx],1);
}
 
void del_l(ll idx){
	ans -= sum(ar[idx]-1);
	update(ar[idx],-1);
}
 
void del_r(ll idx){
	ans -= sum(n+5) - sum(ar[idx]);
	update(ar[idx],-1);
}
 
bool cmp(query &a , query& b){
	if(a.L/BLOCK != b.L/BLOCK){
		return a.L/BLOCK < b.L/BLOCK;
	}
	return a.R < b.R;
 
}
 
int main(){
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	cin>>n;
	BLOCK = (ll)sqrt(n);
	ll br[n+1];
	ll c = 1;
	FOR(i,n){
		cin>>ar[i];
		br[i] = ar[i];
	}
	sort(br,br+n);
	FOR(i,n){
		if(!mp.count(br[i])) mp[br[i]] = c++;
	}
	FOR(i,n) ar[i] = mp[ar[i]];
	ll q;
	cin>>q;
	for(int i = 0 ; i < q ; i++){
		cin>>qq[i].L>>qq[i].R;
		qq[i].L-- , qq[i].R--;
		qq[i].pos = i;
	}
	sort(qq,qq+q,cmp);
/*	for(int i = 0 ; i < q ; i++){
		cout<<qq[i].L<<" "<<qq[i].R<<" "<<qq[i].pos<<" \n";
	}*/
	ll currL = 0, currR = -1;
	for(int i = 0 ; i < q ; i++){
		ll L = qq[i].L , R = qq[i].R;
		while(currL > L){
			add_l(--currL);
		}
		while(currR < R){
			add_r(++currR);
		}
		while(currL < L){
			del_l(currL++);
		}
		while(currR > R){
			del_r(currR--);
		}	
		res[qq[i].pos] = ans;
	}
	FOR(i,q){
		cout<<res[i]<<endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
