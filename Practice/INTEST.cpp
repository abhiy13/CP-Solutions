#include <bits/stdc++.h>
	using namespace std;
 
#define io std::ios::sync_with_stdio(false);cin.tie(NULL);
typedef long long LL;
 
int main(){
	//freopen("input.txt" , "r" , stdin);
    io;
    LL t , n;
    LL cnt=0;
   	scanf("%lld %lld" , &t , &n);
    while(t--){
    	LL k; 
    	scanf("%lld" , &k);
    	if(k%n==0) cnt++;
    }
    cout<<cnt;
	return 0;
} 
