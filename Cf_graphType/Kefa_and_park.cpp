#https://codeforces.com/contest/580/problem/C

#include<bits/stdc++.h>
using namespace std;

int n = 1e5 + 5,m;
vector<vector<int>>graph(n);
vector<int>a(n);
int ans=0;


void  dfs(int u,int parent,int maxCat,int  Cat)
{
    if(a[u])
    {
        Cat++;
    }
    else
    {
        Cat=0;
    }
    maxCat=max(Cat,maxCat);
    int children=0;
    for(auto v:graph[u])
    {
        if(v!=parent)
        {
            dfs(v,u,maxCat,Cat);
            children++;
        }
    }
    if(children==0 && maxCat<=m)
    {
        ans++;
    }
}
int main()
{

    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=1; i<=n-1; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1,-1,0,0);
    cout<<ans<<endl;

}

