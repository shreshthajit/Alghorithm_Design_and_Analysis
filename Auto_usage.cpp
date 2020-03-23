#include<bits/stdc++.h>

using namespace std;


void addEdge(vector<int>add[],int u,int v)
{
add[u].push_back(v);
add[v].push_back(u);
}
void printGraph(vector<int>add[],int V){
for(int v=0;v<V;v++)
cout<<"\n the adjacency list vertex"<<v<<endl;

for(auto x : adj[v])
cout<<"-> "<< x;
cout<<endl;

}
int main(){

int v=5;

vector<int>adj[v];

addEdge(adj,0,1);
addEdge(adj,0,4);
addEdge(adj,1,2);
addEdge(adj,1,3);
addEdge(adj,1,4);
addEdge(adj,2,3);
addEdge(adj,3,4);
printGraph(adj,v);



}
