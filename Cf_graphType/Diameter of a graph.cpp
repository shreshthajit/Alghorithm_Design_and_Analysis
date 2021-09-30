Learning Target:
---------------------------------------------
How can we use he basic properties of a graph and a tree to check if it is possible to
create a graph with n nodes,m edges and a Diameter<=k

Key observations:
1.when there are n nodes we have nC2 or n*(n-1)/2 edges
2.number of eges should be m>=n-1
3.A tree is a graph with minimum edges
4.A diameter of a tree is the maximum distance between any two nodes in a tree
5.The same idea aplies to a graph.
6.We have to make the graph connected and not have any self loops
7.So we need to find diameter <=k

idea:
1.We need to make the nodes as close as possible
2.for exaple:
1-2
1-3
1-5
1-6
is the best example as we have maximum diameter=2
  
so if k>=2 we have the ans=Yes
but if k==1 then we have the ans=No because then we have connect it in such a way that the number of edges>n*(n-1)/2
if k==0 then there will have to be one node where n=1
  ----------------------------------------------------------------------------------------------
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
    cout<<"? "<<node<<endl;
    for(int i=1; i<=n; i++)
        cin>>dist[i];
}
void addEdge(int u,int v)
{
    edges.push_back({u,v});
}

bool isPrime(int num)
{
    bool flag=true;
    for(int i = 2; i <= num / 2; i++)
    {
        if(num % i == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long  n,m,k;
        cin>>n>>m>>k;
        k -=2;//because diameter should be <k-1 that is equal to k-2
        if(m<n-1)//the graph is not connected
        {
            cout<<"No"<<endl;
        }
        else if(m>((n*(n-1))/2)) ///there are multiple edges
        {
            cout<<"No"<<endl;
        }
         else if(k<=-1)
            cout<<"No"<<endl;
        else if(k==0)
        {
            if(n==1)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }

        else if(k==1)
        {
            if(m==(n*(n-1))/2)///this is possible when the graph is a complete graph
            {
                cout<<"Yes"<<endl;
            }
            else
                cout<<"No"<<endl;
        }
        else
            cout<<"Yes"<<endl;///then it is always possible.

    }
}

 





