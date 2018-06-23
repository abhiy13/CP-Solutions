#include "bits/stdc++.h"
	using namespace std;
 
int main(){
	int n , k;
	cin>>n>>k;
	int box[n];
	for(int i = 0 ; i < n ; i++) cin>>box[i];
	vector<int> commands;
	int a;
	while(1){
		cin>>a;
		if(a==0) break;
		else commands.push_back(a);
	}
	int stac=0;
	int move = 0;
	int ss = commands.size();
	queue <int> st;
	for(int i = 0 ; i < ss ; i++){
		if(commands[i] == 3){
			if(box[move]!=0 && stac == 0){
				box[move] -= 1;
				stac += 1;
				st.push(move);
			}
		}
		if(commands[i] == 4){
			if(stac==0) continue;
			if((box[move]+1) <= k){
				box[move] += 1;
				stac--;
				st.pop();
			}
		}
		if(commands[i] == 1){
			if(move==0) continue;
			move--;
		}
		if(commands[i] == 2){
			if(move==n-1) continue;
			move++;
		}
	}
	/*if(st.size()!=0){
		while(st.size() != 0){
			int m = st.front();
			box[m]++;
			if(box[m]>k) box[m]--; 
			st.pop();
		}
	}*/
	for(int i = 0 ; i < n ; i++){
		cout<<box[i]<<" ";
	}
	return 0;
} 
