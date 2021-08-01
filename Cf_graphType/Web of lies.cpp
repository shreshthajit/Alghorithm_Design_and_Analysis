#https://codeforces.com/contest/1549/problem/C

///What we will learn from this problem:
///1.How to add and remove edges from a graph by using adjacency matrix of
///the graph
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
    int n,m;
    cin>>n>>m;
    vector<set<int>>graph(n+1);
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    vector<bool>isGood(n+1);
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        if(graph[i].lower_bound(i)==graph[i].end())
        {
            ans++;
            isGood[i]=true;
        }
    }

    int q;
    cin>>q;
    while(q--)
    {
        int type;
        cin>>type;
        if(type==3)
        {
            cout<<ans<<endl;
        }
        else
        {
            int u,v;
            cin>>u>>v;
            if(isGood[u])ans--;
            if(isGood[v])ans--;

            if(type==1)
            {
                graph[u].insert(v);
                graph[v].insert(u);
            }
            else
            {
                graph[u].erase(v);
                graph[v].erase(u);
            }

            if(graph[u].lower_bound(u)!=graph[u].end())
            {
                isGood[u]=false;
            }
            else
            {
                isGood[u]=true;
            }

            if(graph[v].lower_bound(v)!=graph[v].end())
            {
                isGood[v]=false;
            }
            else
            {
                isGood[v]=true;
            }

            if(isGood[u])ans++;
            if(isGood[v])ans++;
        }
    }
}

