#https://codeforces.com/contest/1151/problem/B

In this problem we need to select a number from every row so that
the XOR of all the numbers is greater than 0.

So firstly we will take the XOR of  first value from every row.
if the XOR is greater than zero than we can print our answer.
otherwise:

we know if there are values c1 c2 c3 c4
then the xor of them is =c1 ^ c2 ^ c3 ^ c4
Suppose we named the XOR of them as total
then total ^ c1 = total ...and this total is xor of all element without c1
becuse total =c1 ^ c2 ^ c3 ^ c4
so total ^ c1= (c1 ^ c2 ^ c3 ^ c4)^c1=c2^c3 and this is a good property.
so every time we will remove c1 or c2 or c3 from total by doing xor and test the other 
element from the matrix that gives us the xor greater than zero and then we can add it to our answer.
**********************************************************************************************************************************

#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
    int t=1;
    //// cin>>t;
    while(t--)
    {
        ll n, k,m;
        cin>>n>>m;
        int a[n+1][m+1];
        int xoR=0;

        for(int i = 1; i <= n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cin>>a[i][j];
                if(j==1)
                {
                    xoR=xoR^a[i][j];
                }
            }
        }
        bool ck=false;
        if(xoR>0)
        {
            cout<<"TAK"<<endl;
            for(int i=1; i<=n; i++)
            {
                cout<<1<<" ";
            }
            cout<<endl;
        }
        else
        {
            for(int i = 1; i <= n; i++)
            {
                int new_xoR=xoR;
                for(int j=1; j<=m; j++)
                {
                    new_xoR=new_xoR^a[i][j]^a[i][1];
                    if(new_xoR>0)
                    {
                        ck=true;
                        cout<<"TAK"<<endl;
                        for(int k=1; k<=n; k++)
                        {
                            if(k==i)
                            {
                                cout<<j<<" ";
                            }
                            else
                            {
                                cout<<1<<" ";
                            }
                        }
                        return 0;
                    }
                }
            }
            cout<<"NIE"<<endl;
        }
    }
}











