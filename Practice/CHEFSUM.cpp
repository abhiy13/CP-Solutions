#include <bits/stdc++.h>
	using namespace std;
 
 
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n=0;
        cin>>n;
        long long mins=100000000;
        long long mn=0;
        for(long long i = 0 ; i < n ; i++){
            long long k;
            cin>>k;
            if(k<mins){
                mins=k;
                mn=i+1;
            }            
        }
        cout<<mn<<"\n";
    }
	return 0;
}
 
