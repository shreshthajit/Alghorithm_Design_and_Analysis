#https://codeforces.com/contest/1519/problem/C

























#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod 1000000007
int power(int x,int y)
{
    int temp;
    if(y==0)
        return 1;
    temp=power(x,y/2)%mod;
    if(y%2==0)
        return (temp%mod*temp%mod)%mod;
    else
        return ((x%mod)*((temp%mod*temp%mod)%mod))%mod;
}
void solve()
{
    int n;
    cin>>n;
    vector<int>v1(n+1);
    vector<int>v2(n+1);
    
    for(int i=1; i<=n; i++)
        cin>>v1[i];
    for(int i=1; i<=n; i++)
        cin>>v2[i];
    map<int,vector<int>>m;
    
    for(int i=1; i<=n; i++)
    {
        m[v1[i]].push_back(v2[i]);
    }
    vector<int>temp(n,0);
    int j=0;
    for(auto i:m)
    {
        vector<int>v=i.second;
        sort(v.begin(),v.end(),greater<int>());
        for(int i=1; i<v.size(); i++)
            v[i]=v[i]+v[i-1];
        int n=v.size();
        for(int i=1; i<=n; i++)
        {
            int y=n-(n%i);
            int x=v[y-1];
            temp[i-1]+=x;
        }
    }
    for(auto i:temp)
        cout<<i<<" ";
    cout<<endl;
}
signed main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        solve();
    }
    return 0;
}
