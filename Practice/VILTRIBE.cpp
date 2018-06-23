#include <bits/stdc++.h>
	using namespace std;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int count[2]={0,0};
        int nps=0;
        char prc = 'X';
        for(auto c : s){
            if(c=='A'){
                count[0]++;
                if(prc=='A'){
                    count[0]+=nps;
                    nps=0;
                } else if(prc!='A' && prc!='.') nps=0;
                prc = 'A';
            }else if(c=='B'){
                count[1]++;
                if(prc=='B'){
                    count[1]+=nps;
                    nps=0;
                }else if(prc!='B' && prc!='.') nps=0;
                prc = 'B';
            }
             if(c=='.'){
                nps++;
             }
        } 
        cout<<count[0]<<" "<<count[1]<<"\n";
    }
	return 0;
}
 
