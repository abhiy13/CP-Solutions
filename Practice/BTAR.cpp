/******************************************
*  AUTHOR:         ABHISHEK YADAV         *
*  INSTITUITION:   CHANDIGARH UNIVERSITY  *
******************************************/
#include <bits/stdc++.h>
	using namespace std;
 
typedef long long ll;
 
int main(){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int n , x;
		cin>>n;
		int a[] = {0,0,0,0};
		for(int i = 0 ; i < n ; i++) {
			cin>>x;
			a[x%4]++;
		}
		if((a[1] + a[2]*2 + a[3]*3)%4==0){
			int ans = min(a[1] , a[3]);
			a[1] -= ans;
			a[3] -= ans;
			ans += a[2]/2;
			a[2] %= 2;
			if(a[2]){
				ans += 2;
				a[2] = 0;
				if(a[3]) a[3] -= 2;
				if(a[1]) a[1] -= 2;
			}
			if(a[1]){
				ans += (a[1]/4)*3;
			}
			if(a[3]){
				ans += (a[3]/4)*3;
			}
			cout<<ans<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
	cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	return 0;
} 
