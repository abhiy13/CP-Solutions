#include <bits/stdc++.h>
	using namespace std;
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int T;
	cin>>T;
	string main = "frieza";
	unordered_map < char , int > mp;
	for(auto a : main) mp[a] = true;
	while(T--){
			string s;
			cin >> s;
			int n = (int)s.size();
			for(int i = 0 ; i < n ; i++){
				if(mp[s[i]]){
					int c = 1;
					while(mp[s[i + c]] and i + c < n) c++;
					cout << c;
					i += c - 1;
				}else{
					int c = 0;
					while(!mp[s[i + c]] and i + c < n) c++;
					cout << c;
					i += c - 1;			
				}
			}
			cout << endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
}
 
