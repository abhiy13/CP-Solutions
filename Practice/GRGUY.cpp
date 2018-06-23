#include "bits/stdc++.h"
	using namespace std;
 
#define FOR(i,n) for(int i = 0; i < n ; i++)
 
typedef long long ll;
 
ll chn(ll a){
	return (a==0)?1:0;
}
void chng(ll &a){
	(a==0)?a=1:a=0;
}
 
int main(){
	//freopen("input.txt" , "r" , stdin);
	int t;
	cin>>t;
	while(t--){
		string s[2];
		cin>>s[0]>>s[1];
		ll str = -1;
		ll len = s[0].length();
		if(s[0][0] == '.') str = 0;
		else if(s[1][0] == '.') str = 1;
		if(str==-1) {cout<<"No\n";continue;}
		bool ok = true;
		ll cm = 0;
		FOR(i,len){
			if(s[str][i+1] == '#' && s[str^1][i+1] == '#'){
				ok = false;
				break;
			}
			if(s[str][i+1] == '#'){
					str^=1;
					cm++;
				/*else if(s[str^1][i] == '.'){
					str^=1;cm++;
				}*/
			}
		}
		if(ok) cout<<"Yes\n"<<cm<<endl;
		else cout<<"No\n";
	}
	return 0;
}
/*
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define LIM 200011
#define INF LIM<<3
 
char words[2][LIM];
int main() {
	freopen("input.txt" , "r" , stdin);
    int z;
    scanf("%d", &z);
    while (z--) {
        scanf("%s%s", words[0], words[1]);
        int n = strlen(words[0]);
        int curr = -1, ans = 0;
        for (int i = 0; i < n; i++) {
            bool dirty0 = words[0][i] == '#';
            bool dirty1 = words[1][i] == '#';
            if (dirty0 && dirty1) {
                ans = INF;
                break;
            }
            if (dirty0) {
                if (curr == 0) ans++;
                curr = 1;
            }
            if (dirty1) {
                if (curr == 1) ans++;
                curr = 0;
            }
        }
        if (ans >= INF) {
            printf("No\n");
        } else {
            printf("Yes\n%d\n", ans);
        }
    }
}
*/ 
