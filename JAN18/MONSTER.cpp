/*
	Author: abhiy13(Abhishek)
	Int Elligence;
	Chandigarh University
	Time:-: dd:mm:yyyy hr:mm
*/
#include <bits/stdc++.h>
	using namespace std;
 
#define io ios::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
#define pll pair<llu,llu>
#define pb(x) push_back(x)
#define f first
#define se second
 
typedef long long ll;
typedef unsigned long long llu;
 
int main(){
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
    	io;
    	ll n;
    	cin>>n;
    	ll ar[n];
    	for(ll i = 0 ; i < n ; i++) cin>>ar[i];
    	ll q;
    	cin>>q;
        bool flag = false;
    	while(q--){
    		ll x,y;
            cin>>x>>y;
            if(flag){
                cout<<"0\n";
                continue;
            }
            ll npo = 0;
            for(ll i = 0 ; i < n ; i++){
                if(i>x) {break;}
                if((i&x)==i){
                    ar[i] -= y;
                }
                if(ar[i]<=0) npo++;
            }
            cout<<n-npo<<endl;
            if(npo==n) flag = true;
    	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)1000.00*clock()/CLOCKS_PER_SEC <<" ms\n"; 
	#endif
	return 0;
} 
