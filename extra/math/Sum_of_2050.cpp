#https://codeforces.com/contest/1517/problem/A

we have a number n and we need to find if the number is divisible by 2050 then how many 2050 numbers is making this sum.
For example 2050 numbers are 2050,20500,205000,2050000.........
  
if the number is 22550=20500+2050=2050(10+1)=2050 x 11 = the 1 in the write is created because there is 1 2050 and the 
one in the left is created is because there is one 20500 ans thus we can calculate that every digit in a number is 
created becuase there is such 2050 numbers makeing this number and we will take each of these number and add it to our answer.
                
-------------------------------------------------------------------------------------------------------------------------------
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

    for(int i=1; i<=n; i++)
        cin>>v[i];

    memset(a, -1, sizeof a);

    for(int i=1; i<=n; i++)
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
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n;
        cin>>n;
        long long num=n/2050;
        if(n<2050 || n%2050)
        {
            cout<<-1<<endl;
        }
        else
        {
            int ans=0;
            while(num>0)
            {
                ans=ans+num%10;
                num=num/10;
            }
            cout<<ans<<endl;
        }

    }
    return 0;
}



















