#include "bits/stdc++.h"
	using namespace std;
 
bool cal(int x1 , int y1 , int r1 , int x2 , int y2 , int r2){
	if((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) <= (r1-r2)*(r1-r2)) return true;
	return false;
}
 
int main(){
	int t;
	cin>>t;
	while(t--){
		int x1 , y1 , r1;
		int x2 , y2 , r2;
		string ans;
		cin>>x1>>y1>>r1>>x2>>y2>>r2;
		if(x1==x2 && y1==y2 && r1==r2){
			ans = "C2~C1";
		}else{
			if(x1==x2 && y1==y2){
				if(r1>r2) ans = "C1CC2";
				else ans = "C2CC1";
			}else if(cal(x1,y1,r1,x2,y2,r2)){
				if(r1>=r2) ans = "C1CC2";
				else ans = "C2CC1";
			}
			else ans = "NOT SATISFIED";
		}
		cout<<ans<<endl;
	}
	return 0;
} 
