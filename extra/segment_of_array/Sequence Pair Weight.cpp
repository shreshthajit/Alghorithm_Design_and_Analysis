#https://codeforces.com/contest/1527/problem/C

a1 a2 a3 a4 a5 a6

in this problem we will think like how a single element is contributing to the answer.
  
  
  
  
  
  
  
  
  
  
  

  
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void solve()
{
    ll n, i, j = 0;
    cin >> n;
    ll a[n];
    map<ll, ll> mp;

    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        mp[a[i]] = 0;
    }
    ll ans = 0;
    for(int i=0; i<n; i++)
    {
        ans = ans + mp[a[i]] * (n - i);
        mp[a[i]] += i + 1;
    }
    cout << ans <<endl;
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
}
