#include "iostream"
  using namespace std;
 
int main(){
  int N , Q;
  cin >> N >> Q;
  int ar[N];
  for(int i = 0 ; i < N ; i++) cin >> ar[i];
  int t , i , x;
  while(Q--){
    cin >> t >> i >> x;
    i--;              
    if(t == 1){
      ar[i] = x;
    }else if(t == 2){
      int res = 0 , cz = 0;
      for(int i_ = 0 ; i_ <= i ; i_++){
        cz ^= ar[i_];
        if(cz == x) res++;     
      }
      cout << res << '\n';
    }
  }
  return 0;
} 
