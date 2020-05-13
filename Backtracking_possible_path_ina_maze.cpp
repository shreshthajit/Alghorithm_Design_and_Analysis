#include<bits/stdc++.h>


using namespace std;

bool vis[100][100];

int path=0;
 
int go(vector<vector<int> >v,int sx,int sy,int dx,int dy,int r,int c)
{
    if(sx<0 || sy<0 || sx>=r || sy>=c || v[sx][sy]==0 || vis[sx][sy]==true)
        return false;

    vis[sx][sy]=true;

    if(sx==dx && sy==dy)
        path++;
    go(v,sx,sy+1,dx,dy,r,c);
    go(v,sx,sy-1,dx,dy,r,c);
    go(v,sx+1,sy,dx,dy,r,c);
    go(v,sx-1,sy,dx,dy,r,c);

    vis[sx][sy]=false;
}
int main()
{
    int r,c;

    cin>>r>>c;

    vector<vector<int> >v(r,vector<int>(c));

    for(int i=0; i<r; i++)
    {

        for(int j=0; j<c; j++)
            cin>>v[i][j];
    }
    memset(vis,false,sizeof(vis));
    go(v,0,0,r-1,c-1,r,c);
    cout<<path<<endl;
}
