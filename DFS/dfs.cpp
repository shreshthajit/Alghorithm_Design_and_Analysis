#include<bits/stdc++.h>
using namespace std;

vector<int>g[100];
bool visited[100];
int fin_time[100];
int dis_time[100];
int tim=1;

void dfs(int v)
{
    visited[v]=true;
    dis_time[v]=tim++;
    for(int i=0; i<g[v].size(); i++)
    {
        int u=g[v][i];
        if(!visited[u])
        {
            dfs(u);
        }
    }
    fin_time[v]=tim++;
}

int main()
{
    int node,edge;
    cin>>node>>edge;
    while(edge--)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int src;
    cin>>src;
    dfs(src);
    for(int i=1;i<=node;i++)
        {
            cout<<"Node--->"<<i<<"--";
            cout<<"discover time= "<<dis_time[i]<<"       finishing time= "<<fin_time[i]<<endl;
        }
}
/*
7 6
1 2
1 3
2 4
2 5
3 6
3 7
*/

