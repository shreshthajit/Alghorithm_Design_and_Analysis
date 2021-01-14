#include<bits/stdc++.h>
using namespace std;
#define mod (int) 998244353
#define MOD (int) 1e9+7
#define X 1001100011100001111ll
#define all(a) a.begin(),a.end()
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define loop(i,a,b) for (int i = a; i < b; i++)
#define bloop(i,a,b) for (int i = a ; i>=b;i--)
#define tc(t) int t; cin >> t; while (t--)
#define int long long
#define ll long long
#define pb emplace_back
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define in(x) scanf("%d", &x)
#define rr return 0
#define prec(n) fixed<<setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define inf (int)(1e18)
#define ini(a, i) memset(a, i, sizeof(a))
#define vi vector<int>
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define vii vector<ii>

/*long long  binpow(long long  x, long  n, long  m)
{
    x %= m ;
    long long  res = 1 ;
    while( n > 0)
    {
        if( n & 1 ) res = ( res * x ) % m ;
        ///n >>= 1 ;
        n=n/2;
        x = ( x * x ) % m ;
    }
    return res ;
}*/

/*
long long  binpow(long b, long p, long m)
{
    if(p==0)
        return 1;
    if(p%2==0)
        return (binpow(b,p/2,m)*binpow(b,p/2,m))%m;
    return (binpow(b,p-1,m)*(b%m))%m;
}
*/
long long binpow(long long a, long long b,long long md) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2,md);
    if (b % 2)
        return (res * res * a)%md;
    else
        return (res * res)%md;
}
signed main()
{

    ll a,b,md;
    while(cin>>a>>b>>md)
    {
        a=a%md;

        cout<<binpow(a,b,md)<<endl;
    }

}

