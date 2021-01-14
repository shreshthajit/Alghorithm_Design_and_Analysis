
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

long long  binpow(long long  x, long  n)
{
    long long  res = 1 ;
    while( n > 0)
    {
        if( n & 1 ) {
                res = ( res * x ) ;
                res=res%10;
        }
        n=n/2;
        x = ( x * x );
        x=x%10;
    }
    return res ;
}
signed main()
{
    ll a,b,md;
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        cout<<binpow(a,b)<<endl;
    }
}

