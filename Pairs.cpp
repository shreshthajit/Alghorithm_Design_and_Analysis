#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int> >v;

bool ok(int x,int y)
{
    for(pair<int,int>p: v)
    {
        if(p.first!=x && p.second!=x && p.first!=y && p.second!=y)
        {
            return false;
        }
    }
    return true;
}

int main()
{

    int m,n;

    cin>>n>>m;
    int a,b;

    for(int i=0; i<m; i++)
    {
        cin>>a>>b;
        v.emplace_back(a,b);
    }

    for(int x:
            {
                v[0].first,v[0].second
            })
    {
        if(ok(x,-1))
        {
            puts("YES");
            return 0;
        }
        for(int i=1; i<m; i++)
        {
            if(v[i].first!=x &&  v[i].second!=x)
            {

                if(ok(x,v[i].first) ||  ok(x,v[i].second))
                {
                    puts("YES");
                    return 0;
                }
                break;
            }
        }
    }

    puts("NO");




    ///for(pair<int,int>x:v)
    ///  cout<<x.first<<" "<<x.second<<endl;


}

