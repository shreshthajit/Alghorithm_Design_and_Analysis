#include <bits/stdc++.h>
using namespace std;
int n,make;
int a[1000];

int main()
{
    int n,make;
    cin>>n>>make;
    int a[n+10];

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    int b[n+2][make+2];
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=make;j++)
        {
            if(j==0) b[i][0]=0;
            else b[i][j]=1000;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=make;j++)
        {
            if(i==1)
            {
                if(a[i]<=j)
                {
                    if(j%a[i]==0)
                    {
                        b[i][j]=j/a[i];
                    }
                }
            }
            else
            {
                if(j>=a[i])
                {
                    int q=j-a[i];
                    b[i][j]=min(b[i][q]+1,b[i-1][j]);
                }
                else
                {
                    b[i][j]=min(1000,b[i-1][j]);
                }
            }
        }
    }
    cout<<b[n][make]<<endl;

}
