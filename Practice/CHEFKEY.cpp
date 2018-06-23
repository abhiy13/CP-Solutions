//working on low level input and execution time is high on high level input
#include <iostream>
      using namespace std;
 
int main()
{
int t;
cin>>t;
while (t>0) {
int m , n ,c;
cin>>m>>n>>c;
int count=0;
for (int i = 1; i <=m ;i++) {
  for (int j = 1; j <= n; j++) {
    if(i*j==c)
      count++;
    if(i*j>c)
      break;
  }
}
cout<<count<<endl;
t--;
}
  return 0;
}
 
