#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define gc getchar
#define MOD 1000000007
void fastscan(ll &x)
{
	register int c = gc();
	x = 0;
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
     
 
     
int main() {
    ll t,d1,d2,d3,n,ln,bn,hn;
    fastscan(t);
    vector<ll> l;
    vector<ll> b;
    vector<ll> h;
    while(t--){
        fastscan(n);
        fastscan(ln);
        fastscan(bn);
        fastscan(hn);
        l.push_back(ln);
        b.push_back(bn);
        h.push_back(hn);
        for(int i=0;i<n;i++){
            fastscan(ln);
            fastscan(bn);
            fastscan(hn);
            l.push_back(ln);
            b.push_back(bn);
            h.push_back(hn);
        }
        sort(l.begin(),l.end());
        sort(b.begin(),b.end());
        sort(h.begin(),h.end());
        d1=l[0];
        d2=b[0];
        d3=h[0];
        for(int i=1;i<=n;i++){
            d1=(l[i]-l[i-1]>d1)?l[i]-l[i-1]:d1;
            d2=(b[i]-b[i-1]>d2)?b[i]-b[i-1]:d2;
            d3=(h[i]-h[i-1]>d3)?h[i]-h[i-1]:d3;
            
        }
        cout<<(((d1*d2)%MOD)*d3)%MOD<<"\n";
        l.clear();
        b.clear();
        h.clear();
    }
 
    return 0;
}  
