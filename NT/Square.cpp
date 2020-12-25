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
#define mx 10000

int tree[mx];

void build(int node,int tl,int tr,vector<ll>arr)
{
    if(tr==tl)
    {
        tree[node]=arr[tl];
        return;
    }
    int mid=(tr+tl)/2;

    build(2*node,tl,mid,arr);
    build(2*node+1,mid+1,tr,arr);

    ///tree[node]=tree[2*node]+tree[2*node+1];
}
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

signed main()
{

    tc(t){
    ll n;
    cin>>n;
    ll a=gcd(4*n,n+1);
    ll lc=(4*n*(n+1))/a;
    cout<<lc/(n+1)+1<<endl;
    }
}


