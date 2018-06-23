#include <stdio.h>
#include <string.h>
#include <iostream>
      using namespace std;
 
int main()
{
string s;
int t;
int count=0;
cin>>t;
while(t>0){
  cin>>s;
  count = 0;
for(int i=0;i<s.size();i++){
  if(s[i]=='<')
    s[i]='>';
  else if (s[i]=='>')
    s[i]='<';
    }
for (int i = 0; i <s.size(); i++) {
if(s[i]=='>')
    if(s[i+1]=='<')
      count++;
}
printf("%d \n",count);
t--;
}
  return 0;
}
 
