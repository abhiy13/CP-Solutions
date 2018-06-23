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
    	string s;
    	cin>>s;
    	int cn = 0;
    	if(s[7] != s[0]) cn++;
    	for(int i = 0 ; i < 7 ; i++){
    		if(s[i]!=s[i+1]) cn++;
    	}
    	if(cn>2) cout<<"non-uniform\n";
    	else cout<<"uniform\n";
    }
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)1000.00*clock()/CLOCKS_PER_SEC <<" ms\n"; 
	#endif
	return 0;
} 
