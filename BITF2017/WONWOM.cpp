#include <bits/stdc++.h>
  using namespace std;
 
int myCompare(string X, string Y)
{
    string XY = X.append(Y);
 
    string YX = Y.append(X);
 
    return XY.compare(YX) > 0 ? 1: 0;
}
 
void printLargest(vector<string> arr)
{
 
    sort(arr.begin(), arr.end(), myCompare);
 
    for (int i=0; i < arr.size() ; i++ )
        cout << arr[i];
}
 
int main()
{
    vector<string> arr;
    long n;
    cin>>n;
    string s;
    for(long i=0;i<n;i++){
      cin>>s;
      arr.push_back(s);
    }
    printLargest(arr);
   return 0;
} 
