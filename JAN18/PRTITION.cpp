/*
  Author: abhiy13(Abhishek)
  Int Elligence;
  Chandigarh University
  Time:-: dd:mm:yyyy hr:mm
*/
#include <bits/stdc++.h>
  using namespace std;
 
#define io ios::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
#define pll pair<llu,llu>
#define pb(x) push_back(x)
#define f first
#define se second
 
typedef long long ll;
typedef unsigned long long llu;
 
vector <long long> ar(1);
bool flag = true;
 
 
bool checkSum(long long sumLeft[], long long k)
{
  long long r = true;
  for (long long i = 0; i < k; i++)
  {
    if (sumLeft[i] != 0)
      r = false;
  }
 
  return r;
}
bool subsetSum( vector <long long> S, long long n, long long sumLeft[], long long A[], long long k)
{
  if (checkSum(sumLeft, k))
    return true;
  if (n < 0)
    return false;
  bool res = false;
  for (long long i = 0; i < 2; i++){
    if (!res && (sumLeft[i] - S[n]) >= 0){
      A[n] = i + 1; 
      sumLeft[i] = sumLeft[i] - S[n];     
      res = subsetSum(S, n - 1, sumLeft, A, k);
      sumLeft[i] = sumLeft[i] + S[n];
    }
  }
  return res;
}
 
bool partition(vector <long long> S, long long n, long long k , long long sf){
  if (n <= k){
    return false;
  }
 
  long long sum = ((n*(n+1))/2) - sf; 
  long long A[n], sumLeft[k];
  for (long long i = 0; i < k; i++)
    sumLeft[i] = sum/k;
  bool res = !(sum % k) && subsetSum(S, n - 1, sumLeft, A, k);
  if (!res){
    return false;
  }
  for (long long i = 0; i < k; i++){
      for (long long j = 0; j < n; j++)
      if (A[j] == 1)
        ar[j] = 0;
      else ar[j] = 1;
  }
  return true;
}
 
int main(){
  #ifdef ABHI
    freopen("input.txt" , "r" , stdin);
  #endif
    io;
    int t;
    cin>>t;
    while(t--){
      ll k = 0  , n = 0;
      cin>>k>>n;
      if(n<=2){
        cout<<"impossible\n";
        continue;
      }
      if(n<=10000){
        vector<long long> arr(n);
        ar.resize(n,0);
        ar[k-1]=2;
        for(long long i = 1 ; i <= n ; i++ ){
          if(i==k) {ar[i-1] = 0; continue;}
          arr[i-1] = i;
        }
        if(!partition(arr, n , 2 , k)) cout<<"impossible";
        else {
             ar[k-1] = 2;
             for(long long i = 0 ; i < n ; i++) cout<<ar[i];
        }
        cout<<endl;
      }else{
        int ar[n+1];
        memset(ar,0,sizeof(ar));      
        ar[k] = 2;
        bool flag = false;
        ll sum = (((n*(n+1))/2) - k);
        if(sum%2 != 0) {cout<<"impossible\n";continue;}
        sum/=2;
        ll sm=0;
        while(!flag){
          for(ll i = n ; i >= 1 ; i--){
            if(i==k) continue;
            sm+=i;
            if(sm==sum){
              ar[i] = 1;
              flag = true;
              break;
            }
            if(sm>sum){
              ll pp = sm-sum;
              if((i-pp) != k){
                ar[i-pp] = 1;
                ar[i] = 0;
                flag = true;
                break;
              }
            }
            if(sm<sum){
              ar[i] = 1;
            }
          }
        }
        for (ll i = 1; i < n+1; ++i){
          cout<<ar[i];
        }
        cout<<endl;
      }
    }
  #ifdef ABHI
    cerr<<"Time Elapsed "<<(double)1000.00*clock()/CLOCKS_PER_SEC <<" ms\n"; 
  #endif
  return 0;
} 
