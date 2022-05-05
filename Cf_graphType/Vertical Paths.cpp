### https://codeforces.com/contest/1675/problem/D

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>v(n+1);
        int root;
        vector<bool> visited(n+1,false);

        vector<int>parent(n+1);
        vector<vector<int>>ans;
        vector<vector<int>>g(n+1);

        vector<int>temp;
        for(int i=1; i<=n; i++)
        {
            cin>>v[i];
            if(v[i]==i)
                root=v[i];


            int a=v[i];
            int b=i;
            parent[i]=v[i];

            if(v[i]!=i)
            {
                g[a].push_back(b);
                g[b].push_back(a);
            }
        }
        for(int i=1; i<=n; i++)
        {
            if(parent[i]!=i)
            {
                if(g[i].size()==1)
                {
                    int cur=i;
                    temp.push_back(cur);
                    visited[cur]=true;
                    while(!visited[parent[cur]])
                    {

                        cur=parent[cur];
                        temp.push_back(cur);
                        visited[cur]=true;

                    }
                    reverse(temp.begin(),temp.end());
                    ans.push_back(temp);
                    temp.clear();
                }
            }
        }

        if(ans.size()==0){
            cout<<1<<endl;
            cout<<1<<endl;
            cout<<1<<endl;
        }

        else
        {
            cout<<ans.size()<<endl;
            for(auto it:ans)
            {
                cout<<it.size()<<endl;
                for(auto child:it)
                {
                    cout<<child<<" ";
                }
                cout<<endl;
            }
        }

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
