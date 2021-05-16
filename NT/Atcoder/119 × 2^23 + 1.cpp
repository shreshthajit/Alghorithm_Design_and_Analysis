#https://atcoder.jp/contests/arc119/tasks/arc119_a

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ll n;
    cin>>n;
    ll ans=1e18;
    for(ll b=0; b<=60; b++)
    {
        ll B=1ll<<b;
        ll a=n/B;
        ll c=n-a*B;
        ans=min(ans,a+b+c);
    }
    cout<<ans<<endl;
}
