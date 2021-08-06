dp[0]=0
    
  dp[1]=1
  dp[2]=2
  dp[3]=3;
  dp[4]=4
  ......
  dp[9]=9
      
      
                                                   dp[457]
                                                   |
                                                   |
                                                   |
                                                   |
                                         
      
              min(dp[457-4],                          dp[457-5],                             dp[457-7])
                      |                               |
                      |                               |
                   dp[453]                            dp[452]
            min(dp[453-4],dp[453-5],dp[453-3])      min(dp[452-4],dp[452-5],dp[452-2])      ans so on 





----------------------------
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
