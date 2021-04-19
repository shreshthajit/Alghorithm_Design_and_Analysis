
#https://codeforces.com/contest/1463/problem/B
It is enough to consider two possible arrays 𝑏: (𝑎1,1,𝑎3,1,𝑎5,…) and (1,𝑎2,1,𝑎4,1,…). It is not
difficult to notice that in these arrays, the condition is met that among two neighboring elements, 
one divides the other. It remains to show that at
least one of these two arrays satisfies the
condition 2∑𝑖=1𝑛|𝑎𝑖−𝑏𝑖|≤𝑆.
  Let's consider 𝑆𝑜𝑑𝑑 — the sum of elements at odd positions and 𝑆𝑒𝑣𝑒𝑛 — the sum of elements at even positions.
  Since 𝑆=𝑆𝑜𝑑𝑑+𝑆𝑒𝑣𝑒𝑛, at least one of the values of 𝑆𝑜𝑑𝑑 and 𝑆𝑒𝑣𝑒𝑛 does not exceed 𝑆2 (because otherwise 
  their sum will be strictly greater than 𝑆). Without losing generality, 
  assume that 𝑆𝑜𝑑𝑑≤𝑆2. Note that for the second variant of the array 𝑏, the condition ∑𝑖=1𝑛|𝑎𝑖−𝑏𝑖|≤𝑆𝑜𝑑𝑑 holds, so 2∑𝑖=1𝑛|𝑎𝑖−𝑏𝑖|≤𝑆.

















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

signed main()
{
    tc(t)
    {
        ll n,k;
        cin>>n;
        ll a[n+1];
        ll cnt[200010];
        bool ck[200010];
        set<ll>st;
        map<ll,bool>mp;
        ll sum=0;
        ll odd=0,even=0;
        for0(i,n)
        {
            cin>>a[i];
            sum=sum+a[i];
            if((i)%2==0)
                even=even+a[i];
            else
                odd=odd+a[i];
        }
        if(even<odd){
            for(int i=0;i<n;i=i+2){
                a[i]=1;
            }
        }
        else{
            for(int i=1;i<n;i=i+2){
                a[i]=1;
            }
        }
        for0(i,n)
        cout<<a[i]<<" ";
        cout<<endl;
    }
}
