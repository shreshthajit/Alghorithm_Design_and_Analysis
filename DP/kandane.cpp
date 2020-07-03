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
#define mx 10000
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

long long  fact(long long n);

long long  ncr(long long  n,long long  r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

long long  fact(long long  n)
{
    long long  res = 1;
    for (long long  i = 2; i <= n; i++)
        res = res * i;
    return res%1000000007;
}

const long long  a = 1000000000;

long long  nCr(long long  n,long long  r)
{
    long long  fac1 = 1,fac2=1,fac;
    for(long long  i=r; i>=1; i--,n--)
    {
        fac1 = fac1 * n;
        if(fac1%i==0)
            fac1 = fac1/i;
        else
            fac2 = fac2 * i;
    }
    fac = fac1/fac2;
    return fac%a;
}
const long long m=1000000007;

int tree[mx];


void build(int node,int tl,int tr,int arr[])
{
    if(tr==tl)
    {
        tree[node]=arr[tl];
        return;
    }
    int mid=(tr+tl)/2;

    build(2*node,tl,mid,arr);
    build(2*node+1,mid+1,tr,arr);

    tree[node]=tree[2*node]+tree[2*node+1];
}

int query_sum(int node,int tl,int tr,int l,int r)
{
    if(l>tr || r<tl)
        return 0;

    if(tl>=l && tr<=r)
        return tree[node];


    int mid=(tl+tr)/2;

    int p1=query_sum(2*node,tl,mid,l,r);
    int p2=query_sum(2*node+1,mid+1,tr,l,r);

    return p1+p2;
}



int kadane(int arr[],int n)
{
    int  max_global,max_current;
    max_global=max_current=arr[0];

    for(int i=1; i<n; i++)
    {
        max_current=max(arr[i],arr[i]+max_global);
        ///cout<<"max_current= "<<max_current<<endl;

        if(max_current>max_global)
            max_global=max_current;
            ///cout<<"max_global= "<< max_global<<endl;
    }

    return max_global;
}
signed main()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    cin>>arr[i];

    cout<<kadane(arr,n);
}
