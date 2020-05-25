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
#define sz(s) s.size()
#define bits(n) __builtin_popcount(n)

const int MAXN = (int)((1e5) + 100);
int gcd(int a, int b)
{
    if (a == 0) return b;
    return gcd(b % a, a);
}

int cuberoot(int x)
{
    int lo = 1, hi = min(2000000ll, x);
    while (hi - lo > 1)
    {
        int mid = (lo + hi) / 2;
        if (mid * mid * mid < x)
        {
            lo = mid;
        }
        else hi = mid;
    }
    if (hi * hi * hi <= x) return hi;
    else return lo;
}

const int dx[4] = { -1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int XX[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int YY[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
const int N =  (int)(1 * 1e6 + 10);

bool comp(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2)
{
    if (p1.fi > p2.first) return true;
    else if (p1.se == p2.se)
    {
        if (p1.se.fi < p2.se.fi) return true;
    }
    return false;
}
vector<int> prefix_function(string s)
{
    int n=(int)s.length();

    vector<int>pi(n);

    for(int i=1; i<n; i++)
    {
        int j=pi[i-1];

        while(j>0 && s[i]!=s[j])
            j=pi[j-1];

        if(s[i]==s[j])
            j++;

        pi[i]=j;
    }
    return pi;
}
int main()
{
    string s;
    cin>>s;
    vector<int>ans=prefix_function(s);

    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";

}
