#https://codeforces.com/contest/1535/problem/C



#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string s;
        cin >> s;
        long long  n=s.size();
        long long  dp[n+1][2];
        memset(dp,0,sizeof(dp));
        if(s[0]=='1' || s[0]=='0')
        {
            dp[0][s[0]-'0']=1;
        }
        else
        {
            dp[0][0]=1;
            dp[0][1]=1;
        }
        for(int i=1; i<s.size(); i++)
        {
            if(s[i]=='1')
            {
                dp[i][1]=dp[i-1][0]+1;
            }
            else if(s[i]=='0')
            {
                dp[i][0]=dp[i-1][1]+1;
            }
            else
            {
                dp[i][1]=dp[i-1][0]+1;
                dp[i][0]=dp[i-1][1]+1;
            }
        }
        long long ans=0;
        for(int i=0; i<s.size(); i++)
        {
            ans+=max(dp[i][0],dp[i][1]);
        }
        cout<<ans<<endl;
    }
}
