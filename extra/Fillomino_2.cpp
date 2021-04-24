#https://codeforces.com/contest/1517/problem/C


In this problem we will be provided that there is n values from 1 to n which is the value of diagonal.

 And we have to make n region such that every region has diagonal number of cells.
  
  for example if n= 2 3 1
     then we can make 
     2 - -
     2 3 -
     3 3 1
    
    so we can take an 2d array and store the diagonal value
    every time we take a value from the diagonal
    and store it in cx and cy and then if the value of the diagonal is x we will run a while loop untill x become 0
    and check if there is a adjacen space in the  cx row .If there is a space in the cx row we will insert the
    same diagonal value into that cell and if there is no space in that row we will go to the next row by 
    increasing cx and thus we will get our answer.

-------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define vll vector<ll>

ll a[600][600];
ll n;
int baki;
void solve()
{
    cin>>n;
    vll v(n+1);

    for(int i=1;i<=n;i++)
    cin>>v[i];

    memset(a, -1, sizeof a);

    for(int i=1;i<=n;i++)
    {
        ll x=v[i];
        ll cx=i, cy=i;
        while(x--)
        {
            a[cx][cy]=v[i];

            if(cy>1 and a[cx][cy-1]==-1)
            cy--;
            else
            cx++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}
int main()
{
    int t=1;
    int cs=0;
    while(t--){
        solve();
    }
    return 0;
}
