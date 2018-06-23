#include <iostream>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
	int t,n,p,c,h,temp,hard,easy;
	cin>>t;
	while(t--) {
	    cin>>n>>p;
	    hard = p/10;
	    easy = p/2;
        c=0;h=0;
	    while(n--) {
	        cin>>temp;
	        if(temp >= easy) c++;
	        if(temp <= hard) h++;
	    }
	    if(c==1&&h==2)cout<<"yes"<<endl;
	    else cout<<"no"<<endl;
	}
} 
