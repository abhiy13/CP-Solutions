/******************************************
*  AUTHOR:         ABHISHEK YADAV         *
*  INSTITUITION:   CHANDIGARH UNIVERSITY  *
******************************************/
#include <bits/stdc++.h>
	using namespace std;
 
typedef long long ll;
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int T;
	cin>>T;
	vector <pair<int,int>> points(123456,{0,0});
	while(T--){
		int N;
		cin>>N;
		int min_start = 1000000000 , x , y;
		points.clear();
		points.reserve(N);
		for(int i = 0 ; i < N ; i++){
			cin>>x>>y;
			points.push_back({y,x});
			if(x < min_start) min_start = x;
		}
		min_start--;
		int cnt = 0;
		sort(points.begin(), points.end());
		for(int i = 0 ; i < N ; i++){
			if(points[i].second > min_start){
				cnt++;
				min_start = points[i].first;
			}
		}
		cout<<cnt<<endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
} 
