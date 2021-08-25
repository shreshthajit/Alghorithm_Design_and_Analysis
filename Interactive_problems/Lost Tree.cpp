#https://codeforces.com/contest/1534/problem/D

Learning targets:
1.How to appraoch an interactive problem
2.Thinking of a problem as a bipatrite graph.
  
Problem statement:
given an unweighted tree with n nodes.Find all the n-1 edges in the trees by asking at most [n/2] queries of the type: ? r

In return to the query you will get the distance from every node to that node r.
 
Steps:
1.root the tree with the node 1 because we need at least 1 query.
  
     1 2 3 4
dist:0 1 2 2
  dist from node 1 to 1 is 0.distance from node 1 to node 2 is 1 and so on.
  
  so for example:
query(r):this will give us a distance array dist[] which represents the distance from node r
dist[i] represents the distance from node r to x;

2.Since we are asking at most [n/2] queries we can think of partitioning the set of nodes into two sets such that every edges goes from 1 set to the other and 
  ask queries from the smaller set to the larger set.

3.Realisation:this is the definition of bipartiteness.

4.if the graph is like 1->3->5->4->2 then we can ask for query(3) and query(4) and thus we can get all the edges because 3 is connected with 1 and 5 on the otherhand
4 is connected with 5 and 2.
 
5.So we can think of colouring the node with yellow and black.so if the dist[x] is even we will color that node black and if the node is yellow
we will color the node yellow.
  
  
  #include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
const ll mod = 1e9 + 7,inf = 1e18;
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void setIO()
{
    fast;
}
int n=2005;
vi dist(n);
vvi edges;
void query(int node)
{
    cout<<"? "<<node<<endl;///everytime we are asking question and we are taking the distance array
    for(int i=1; i<=n; i++)
        cin>>dist[i];
}
void addEdge(int u,int v)
{
    edges.push_back({u,v});this will add the connect node with one another
}

int main()
{
    setIO();
    cin>>n;
    query(1);
    vi yellowNodes;
    vi blackNodes;
    for(int i=2; i<=n; i++)
    {
        if(dist[i]%2==0)
        {
            blackNodes.push_back(i);
        }
        else
        {
            yellowNodes.push_back(i);
        }
        if(dist[i]==1)
            addEdge(i,1);
    }

    if(blackNodes.size()<yellowNodes.size())
    {
        for(auto node:blackNodes)
        {
            query(node);
            for(int i=2; i<=n; i++)//we are counting from i=2 because we have already taken the node 1.
            {
                if(dist[i]==1)//we are taking those nodes with distance 1 because we are quering everytime from taking nodes from blackNodes
                {
                    addEdge(i,node);
                }
            }
        }
    }
    else
    {
        for(auto node:yellowNodes)
        {
            query(node);
            for(int i=2; i<=n; i++)
            {
                if(dist[i]==1)
                {
                    addEdge(i,node);
                }
            }
        }
    }
    cout<<"!"<<endl;
    for(auto edge:edges)
    {
        cout<<edge[0]<<" "<<edge[1]<<endl;
    }
    return 0;

}

  
