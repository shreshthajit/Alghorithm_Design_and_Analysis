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
//#define int long long
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
#define sz(s) s.size()
#define bits(n) __builtin_popcount(n)
#define mx 10000
const int MAXN = (int)((1e5) + 100);

ll dx[4]= {1,0,-1,0};
ll dy[4]= {0,1,0,-1};
signed main()
{

    ll n,m;
    cin>>n>>m;
    string s[n];
    for0(i,n)
    cin>>s[i];

    ll a[]= {0,1,2,3};
    ll sx,sy;
    ll ex,ey;

    for0(i,n)
    for0(j,m)
    {
        if(s[i][j]=='S')
            sx=i,sy=j,s[i][j]='.';
        else if(s[i][j]=='E')
            ex=i,ey=j,s[i][j]='.';
    }

    string path;
    cin>>path;

    ll ans=0;

    bool ck=true;


    while(ck)
    {
        ll x=sx,y=sy;
        for0(i,path.size())
        {
            if(x==ex && y==ey)
                break;
            x=x+dx[a[path[i]-'0']];
            y=y+dy[a[path[i]-'0']];
            if(x<0 || x>=n || y>=m || y<0 || s[x][y]=='#')
                break;
        }
        if(x==ex && y==ey)
            ans++;
            ck=next_permutation(a,a+4);
    }
    cout<<ans<<endl;
}

