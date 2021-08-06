#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
     vector<int>dp(n+1);
    dp[0]=0;
    for(int i=1; i<=n; i++)
    {
        int temp=i;
        int min_val=1e6+2;
        while(temp!=0)
        {
            int digit=temp%10;
            temp/=10;
            if(digit==0)continue;
            min_val=min(min_val,1+dp[i-digit]);
        }
        dp[i]=min_val;
    }
    cout<<dp[n]<<endl;
}
