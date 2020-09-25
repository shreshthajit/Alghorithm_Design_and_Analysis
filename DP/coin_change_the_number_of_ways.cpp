#include<bits/stdc++.h>

using namespace std;

int knapsack(int arr[],int n,int  coin)
{

    int dp[coin+1][n+1];
    for(int i=0; i<=coin; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i>=0 && j==0)
                dp[i][j]=1;
            else if(i==0 && j>0)
                dp[i][j]=0;
            else
            {
                if(arr[i-1]<=j)
                    dp[i][j]=dp[i-1][j]+dp[i][j-arr[i-1]];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[coin][n];
}
int main()
{
    int sum;
    while(cin>>sum){
    ///int sum;
    ///cin>>sum;
    int ar[100]= {50,25,10,5,1};
    sort(ar,ar+5);
    cout<<knapsack(ar,sum,5)<<endl;
    }
}
