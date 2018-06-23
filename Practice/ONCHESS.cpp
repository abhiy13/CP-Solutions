#include <bits/stdc++.h>
#include <string>
	using namespace std;
 
struct chess{
	int R=0;
	int min=0;
	int max=0;
	int time=0;
	char ra[10]="rated";
	char col[10]="black";
};
 
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		chess a[n];
		for(int i = 0 ; i<n ; i++){
			cin>>a[i].R>>a[i].min>>a[i].max>>a[i].time>>a[i].ra>>a[i].col;
		}
		bool isv[n];
		memset(isv,false,sizeof(isv));
		for(int i = 0 ; i<n ;i++){
			bool flag = false;
			for(int j = 0 ; j < i ;j++){
				if(isv[j]) continue;
			//	cout<<a[i].R<<" "<<a[j].R<<" "<<a[i].min<<" "<<a[i].max<<" "<<a[j].min<<" "<<a[j].max<<" "<<a[i].time<<" "<<a[i].col<<" "<<a[i].ra<<" "<<a[j].time<<" "<<a[j].col<<" "<<a[j].ra<<"\n";
				if((a[j].R>=a[i].min && a[j].R<=a[i].max) && (a[i].R>=a[j].min && a[i].R<=a[j].max) && (a[j].time==a[i].time) && !(strcmp(a[i].ra,a[j].ra)) && (!(strcmp(a[i].col,"random")) && !(strcmp(a[j].col,"random")) || (strcmp(a[i].col,a[j].col)))) {cout<<j+1<<"\n";isv[j]=true;isv[j]=true;flag=true;break;}	
			}
			if(!flag) cout<<"wait\n";
		}
	}
	return 0;
}
 
