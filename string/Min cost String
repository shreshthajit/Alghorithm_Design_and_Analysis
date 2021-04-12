#include<bits/stdc++.h>
#define forr(i,start,count) for (int i = (start); i < (start)+(count); ++i)
#define set_map_includes(set, elt) (set.find((elt)) != set.end())
#define readint(i) int i; cin >> i
#define readll(i) ll i; cin >> i
#define readdouble(i) double i; cin >> i
#define readstring(s) string s; cin >> s

typedef long long ll;

using namespace std;

const ll modd = (1000LL * 1000LL * 1000LL + 7LL);

string q;

void printCircuit(vector< vector<int> > adj)
{
    // adj represents the adjacency list of
    // the directed graph
    // edge_count represents the number of edges
    // emerging from a vertex
    unordered_map<int,int> edge_count;

    for (int i=0; i<adj.size(); i++)
    {
        edge_count[i] = adj[i].size();
    }

    if (!adj.size())
        return; //empty graph

    // Maintain a stack to keep vertices
    stack<int> curr_path;

    // vector to store final circuit
    vector<int> circuit;

    // start from any vertex
    curr_path.push(0);
    int curr_v = 0; // Current vertex

    while (!curr_path.empty())
    {
        // If there's remaining edge
        if (edge_count[curr_v])
        {
            // Push the vertex
            curr_path.push(curr_v);
            // Find the next vertex using an edge
            int next_v = adj[curr_v].back();

            // and remove that edge
            edge_count[curr_v]--;
            adj[curr_v].pop_back();

            // Move to next vertex
            curr_v = next_v;
        }
        // back-track to find remaining circuit
        else
        {
            circuit.push_back(curr_v);

            // Back-tracking
            curr_v = curr_path.top();
            curr_path.pop();
        }
    }
    // we've got the circuit, now print it in reverse
    cout<<circuit.size()<<endl;
    for (int i=circuit.size()-1; i>=0; i--)
    {
        q += 'a'+circuit[i];
    }
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout.precision(12);


    int test_cases = 1;
    forr(t, 1, test_cases)
    {
        int n,k;
        cin>>n>>k;
        vector<vector<int>> adj(k);
        forr(i,0,k)
        {
            forr(j,0,k)
            {
                adj[i].push_back(j);
            }
        }

        printCircuit(adj);

        q.pop_back();
        string s;

        while (s.size()<n)
        {
            for(auto c : q)
            {
                s += c;
            }
        }
        s.resize(n);
        cout << s << endl;

    }

    return 0;
}

