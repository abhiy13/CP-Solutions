#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL; 
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL, LL> pll;
 
const int MAX = 1e3 + 3;
 
int a[MAX];
vector<int> moves;
 
int main() {
	int n, k, cnt = 0;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; ++i) {
		if (a[i] < 0) {
			moves.push_back(i+1);	//for 1-base indexing
			a[i] *= -1;
			a[i+1] *= -1;
		}
	}
	printf("%d\n", (int)moves.size());
	for(int i = 0; i < moves.size(); ++i) {
		printf("%d%c", moves[i], i == moves.size()-1 ? '\n' : ' ');
	}
	return 0;
}   
