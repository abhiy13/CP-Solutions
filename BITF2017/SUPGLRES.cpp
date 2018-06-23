#include <bits/stdc++.h>
	using namespace std;
 
#define debug(x) cout<<x<<"\n";
#define io ios::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n"
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define f first
#define se second
 
typedef long long LL;
typedef unsigned long long ULL;
 
bool solve(long arr[], long n)
{
    if (n == 0 || n == 1)
        return true;
    for (int i = 0; i < n; i += 2)
        if (arr[i] > arr[i + 1])
            return false;
    return true;
}
 
int main() 
{
   long n;
   cin>>n;
   long arr[n];
   for (size_t i = 0; i < n; i++)
   {
      cin>>arr[i];
   }
   if (solve(arr, n))
       printf("Yes\n");
   else
       printf("No\n");       
   return 0;
} 
