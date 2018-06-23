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
 
vector <string> ss;
 
void subString(string s) {
    ll n = s.size();
    for (ll i = 0; i < n; i++) 
        for (ll len = 1; len <= n - i; len++)
            ss.push_back(s.substr(i, len));
}
 
int main(){
    #ifdef ABHI
        freopen("input.txt" , "r" , stdin);
    #endif
    io;
    string s;
    cin>>s;
    subString(s);
    string pp;
    ll kk = ss.size();
    sort(ss.begin(),ss.end());
    string sm;
    for(int i = 0 ; i < kk ; i++) sm+=ss[i];
    ll q;
    cin>>q;
    ll g = 0 , p=0 , m=0 ,ans = 0;
    while(q--){
        ans = 0;
        cin>>p>>m;
        ans = (p*g)%m +1;
        cout<<sm[ans-1]<<endl;
        g+=sm[ans-1];
        }
    #ifdef ABHI
        cerr<<"Time Elapsed "<<(double)1000.00*clock()/CLOCKS_PER_SEC <<" ms\n"; 
    #endif
    return 0;
} 
