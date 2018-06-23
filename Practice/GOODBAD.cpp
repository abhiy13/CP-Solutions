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
    int t;
    cin>>t;
    while(t--){
    	int n , f;
    	cin>>n>>f;
    	string s;
    	cin>>s;
    	int l = 0 , u = 0;
    	for(int i = 0 ; i < n ; i++){
    		if(isupper(s[i])) u++;
    		else l++;
    	}
    	if( f >= l && f >= u) cout<<"both\n";
    	else if(u > l && u >= n-f ) cout<<"brother\n";
    	else if(l > u && l >= n-f) cout<<"chef\n";
    	else cout<<"none\n";
    }
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)1000.00*clock()/CLOCKS_PER_SEC <<" ms\n"; 
	#endif
	return 0;
} 
