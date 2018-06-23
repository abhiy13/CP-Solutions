#include <bits/stdc++.h>
	using namespace std;
 
const int MAXN = 1e6 + 5;
 
using ll = long long;
ll spf[MAXN] = {0};
 
//reference from geeksforgeeks sieve
 
void sieve(){
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
    for (int i=3; i*i< MAXN; i++){
        if (spf[i] == i){
          for (int j=i*i; j<MAXN; j+=i)
            if (spf[j]==j)
              spf[j] = i;
        }
    }
}
 
unordered_set <ll> getFactorization(ll x)
{
    unordered_set <ll> ret;
    while (x != 1)
    {
        ret.insert(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
		ofstream fout("DEBUG.txt");
	#endif
	sieve();
	ll prefix[MAXN + 1];
	prefix[0] = 0;
	prefix[1] = 0;
	for(int i = 2 ; i < MAXN ; i++){
		ll x = getFactorization(i).size();
//		fout <<  i << " " << x << "\n";
		prefix[i + 1] = prefix[i] + x;
	}
	int T;
	cin>>T;
	while(T--){
		ll l , r;
		cin >> l >> r;
		cout << prefix[r] - prefix[l] << endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
}
 
