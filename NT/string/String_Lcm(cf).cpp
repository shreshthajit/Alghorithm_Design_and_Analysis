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

int power(int x, int n, int m)
{
    x %= m ;
    int res = 1 ;
    while( n > 0)
    {
        if( n & 1 ) res = ( res * x ) % m ;
        ///n >>= 1 ;
        n=n/2;
        x = ( x * x ) % m ;
    }
    return res ;
}

signed main()
{

    string s1,s2;
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>s1>>s2;
        string a=s1,b=s2;
        while(1)
        {
            if(a.length()==b.length())
            {
                if(a==b){
                     cout<<a<<endl;
                     break;
                }
                else
                {
                    cout<<-1<<endl;
                    break;
                }
            }
            else
            {
                if(a.length()<b.length())
                    a=a+s1;
                else
                    b=b+s2;
            }
        }
    }
}
