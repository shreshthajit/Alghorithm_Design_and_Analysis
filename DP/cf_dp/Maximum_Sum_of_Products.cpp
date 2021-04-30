#https://codeforces.com/contest/1519/problem/D
In this problem we can reverse a sub array so that sum of ai x bi is maximized.
 
For this we will manage a prefix ara and a suffix array that will store the cummulative sum from the front and from the back.
 
For examle

5
2 3 2 1 3
1 3 2 4 2
after mult: 2 9 4 4 6
pref-->     2 11 15 19 25
suff-->     25 23 14 10 6
 
No we will take a 2D array called dp which will store the values if we reverse any length of subarray.
dp[1][1]=2
dp[2][2]=9
dp[3][3]=4
dp[4][4]=4
dp[5][5]=6
dp[4][5]=dp[4+1][5-1]+a[4] x b[5] + a[5] x b[4]=dp[5][4] + 14=0+14=14;
same
dp[3][4]=dp[4][3]+8+2= 0+10 = 10;
dp[3][5]=dp[4][4]+4+6=4+10=14;
dp[2][3]=dp[3][2]+6+6=12;
dp[2][4]=dp[3][3]+12+3=19;
dp[2][5]=dp[3][4]+6+9=25;
dp[1][2]=dp[2][1]+6+3=9;
dp[1][3]=dp[2][2]+4+2=15;
dp[1][4]=dp[2][3]+8+1=21;
dp[1][5]=dp[2][4]+3+4=32;

In the the code every time we are calculating this dp and adding the max value in our answer.
2 3 2 1 3
in this array if we reverse it we can say that if we previously calculate dp[2][4] then we will add just a[1]*b[5]+a[5]*b[1] with
dp[2][4] we can clearly see that this is a good idea because we just need to calcualte the multiple of terminal value.
  and thus we have taken dp[i+1][j-1] we which give us dp[2][4];
---------------------------------------------------------------------------------------------------------------------------------

#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int Max=5010;
ll a[Max],b[Max],suff[Max],pref[Max];
ll dp[Max][Max];

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=n; i++)
    {
        cin>>b[i];
    }
    pref[0]=0;
    for(int i=1; i<=n; i++)
    {
        pref[i]=pref[i-1]+a[i]*b[i];
    }
    suff[n+1]=0;
    for(int i=n; i>=1; i--)
    {
        suff[i]=suff[i+1]+a[i]*b[i];
    }
    memset(dp,0,sizeof(dp));
    ll ans=pref[n];
    for(int i=n; i>=1; i--)
    {
        dp[i][i]=a[i]*b[i];
        for(int j=i+1; j<=n; j++)
        {
            dp[i][j]=dp[i+1][j-1]+a[i]*b[j]+a[j]*b[i];
            ans=max(ans,pref[i-1]+dp[i][j]+suff[j+1]);
        }
    }
    cout<<ans<<endl;
}
