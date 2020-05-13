#include<bits/stdc++.h>

using namespace std;

bool vis[100][100];

bool go(vector<vector<int>> &v,int sx,int sy,int dx,int dy,int r,int c)
{

    if(sx<0 || sy<0 || sx>=r || sy>=c || vis[sx][sy]==true || v[sx][sy]==0)
        return false;

    if(sx==dx && sy==dy)
        return true;

    vis[sx][sy]=true;

    if(go(v,sx,sy+1,dx,dy,r,c))
        return true;

    if(go(v,sx,sy-1,dx,dy,r,c))
        return true;

    if(go(v,sx+1,sy,dx,dy,r,c))
        return true;

    if(go(v,sx-1,sy,dx,dy,r,c))
        return true;

    return false;

}

int main()
{
    int r,c;
    cin>>r>>c;
    vector<vector<int>>v(r,vector<int>(c));

    int sx=0,sy=0,dx=r-1,dy=c-1;


    memset(vis,false,sizeof(vis));

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin>>v[i][j];
        }
    }

    cout<<go(v,0,0,r-1,c-1,r,c);



}
