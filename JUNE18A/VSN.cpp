#include <bits/stdc++.h>
  using namespace std;
†
typedef long long ll;
typedef long double ld;
†
// Reference from https://stackoverflow.com/questions/6533856/ray-sphere-intersection and answer by St√©phane
†
ld px,py,pz,qx,qy,qz,qqx,qqy,qqz,dx,dy,dz,cx,cy,cz,r;
†
bool is(ld xx){
  qx = qy = qz = 0;
  qx = qqx + (xx*dx);
  qy = qqy + (xx*dy);
  qz = qqz + (xx*dz);
  ld x = ((qx-px)*(qx-px))+((qy-py)*(qy-py))+((qz-pz)*(qz-pz));
  ld y = 2.00*(((qx-px)*(px-cx))+((qy-py)*(py-cy))+((qz-pz)*(pz-cz)));
  ld z = (cx*cx)+(cy*cy)+(cz*cz)+(px*px)+(py*py)+(pz*pz)-(2*((cx*px)+(cy*py)+(cz*pz)))-(r*r);
 // cout<<x<<" "<<y<<" "<<z<<" ";
 // cout<<(y*y)<<" "<<(4*x*z)<<" "<<((y*y)-(4*x*z))<<endl;
  if(((y*y)-(4.00*x*z))<0) return true;
  return false;
}
†
int main(){
  ios::sync_with_stdio(false);
  #ifdef ABHI
    freopen("input.txt" , "r" , stdin);
  #endif
  cout.precision(20);
  cout<<fixed;
  int t;
  cin>>t;
  while(t--){
    cin>>px>>py>>pz>>qqx>>qqy>>qqz>>dx>>dy>>dz>>cx>>cy>>cz>>r;
    ld res = 0.000;
    ld lo = 1 , hi = 1e9;
    for(int i = 0 ; i < 100 ; i++){
      ld mid = (lo+hi)/2.0000;
      if(is(mid)){
        hi = mid - 1;
        res = mid;
      }else{
        lo = mid + 1;
      }
    }
    cout<<res<<endl;
  }
  #ifdef ABHI
    cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
  #endif
  return 0;
} 
