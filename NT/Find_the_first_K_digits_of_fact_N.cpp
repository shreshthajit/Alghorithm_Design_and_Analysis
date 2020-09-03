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


int knapsack(int val[],int wt[],int W,int n)
{
    if(n==0 || W==0)
        return 0;

    if(wt[n-1]>W)
        return knapsack(val,wt,W,n-1);

    else
        return max(val[n-1]+knapsack(val,wt,W-wt[n-1],n-1),knapsack(val,wt,W,n-1));
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

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int lcm(int a, int b)
{
    return (a*b)/gcd(a, b);
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
vector<ll>g[8],cost[8];
ll dist[8];
ll par[8];

ll bfs(ll src,ll dst)
{
    memset(dist,-1,sizeof(dist));
    par[src]=-1;
    dist[src]=0;
    queue<long long>q;
    q.push(src);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(u==dst)
            return dist[dst];

        for(auto v:g[u])
        {
            if(dist[v]==-1)
            {
                dist[v]=dist[u]+1;
                par[v]=u;
                q.push(v);
            }
        }
    }
}

void print_path(ll src,ll dst)
{
    vector<ll>path;
    ll u=dst;
    while(u!=-1)
    {
        path.push_back(u);
        u=par[u];
    }
    reverse(path.begin(),path.end());
    for(auto a:path)
        cout<<a<<" ";
    cout<<endl;
}
const double eps = 1e-9;

/*
This due to precision error when dealing
with real numbers in C++. For example,
due to precision error sometimes a value
which is supposed to be 1, becomes 0.9999999999999.
 The difference between these two values is very small,
 but if we floor them both, the first one
 becomes 1 whereas the second one becomes 0.
  So in order to avoid this error, when flooring
  a positive value we add a small number
   ( epsilon = 0.000000001 ) to the number.
   */
// Find the first K digits of N!
int leadingDigitFact ( int n, int k )
{
    double fact = 0;
    // Find log(N!)
    for ( int i = 1; i <= n; i++ )
    {
        fact += log10 ( i );
    }
    // Find the value of q
    double q = fact - floor ( fact+eps);

    double B = pow ( 10, q );
    // Shift decimal point k-1 \times
    for ( int i = 0; i < k - 1; i++ )
    {
        B *= 10;
    }
    // we have  to floor it
    return floor(B+eps);
}
signed main()
{
    ll n,k;
    cin>>n>>k;
    cout<<leadingDigitFact(n,k)<<endl;
}
/*
7 8
1 2
1 7
2 3
2 4
3 5
3 6
3 7
4 5
*/


