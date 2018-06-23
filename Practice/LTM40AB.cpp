#include <iostream>
 
using namespace std;
 
typedef long long ll;
 
ll solve(ll a, ll b, ll c, ll d)
{
  if (a > b or c > d or d < a)
    return 0;
 
  if (b > d)
    b = d;
 
  if (c < a)
    c = a;
 
  if (b < c)
    return (b-a+1)*(d-c+1);
 
  ll ans = (b-a+1)*(d-c+1);
  ans -= (b-c+1)*(b-c+2)/2;
 
  return ans;
}
 
int main()
{
  int t, a, b, c, d;
  cin >> t;
 
  while (t--)
  {
    cin >> a >> b >> c >> d;
    cout << solve(a,b,c,d) << '\n';
  }
} 
