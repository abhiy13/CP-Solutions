#include "iostream"
     using namespace std;
 
typedef long long ll;
 
int main() {
     ios::sync_with_stdio(false);
     int t;
     cin>>t;
     for(int tt = 1 ; tt <= t ; tt++){
          int n;
          cin>>n;
          int ar[n];
          for(int i = 0 ;i < n ; i++){
               cin>>ar[i];
          }
          int aa[n];
          aa[n-1] = 1;
          for(int i = n-2 ; i > -1 ; --i){
               if((ar[i]>0 && ar[i+1]<0) || (ar[i]<0 && ar[i+1]>0)) aa[i]= aa[i+1] + 1;
               else aa[i] = 1;
          }
          for(int i = 0; i < n ; i++) cout<<aa[i]<<" ";
          cout<<endl;
     }
	return 0;
}
 
