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
                    
 
const int mm  = 1000;
 
int main(){
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
    io;
    int t;
    cin>>t;            
    while(t--){   
      llu k=0; 
      llu p = mm;   
   		for(int i=0 ; i < 4 ; i++){
   			cin>>k; 
               p^=k;
   		}
   		if(p==mm) cout<<"YES\n";
   		else cout<<"NO\n";
   		//cout<<p<<endl;                       
   	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)1000.00*clock()/CLOCKS_PER_SEC <<" ms\n"; 
	#endif
	return 0;
} 
