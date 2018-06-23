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
    	for(unsigned int i = 0 ; i < s.size() ; i++){
    		if(s[i]=='*'){
    			break;
    		}else{
    			cout<<s[i];
    		}
    	}
    	cout<<endl;
    }
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)1000.00*clock()/CLOCKS_PER_SEC <<" ms\n"; 
	#endif
	return 0;
} 
