#https://codeforces.com/contest/1516/problem/C


In this porblem we have to remove some elements so that there will be no options for partion it into two equal sum subsets.
  
1.If the sum of the array is odd then the answer is no
2.If the sum of the array is even then we have options like this:

   
     we will use knapsack and check weather there is a sum so that it equals sum/2 and if it happens then the rest elements sum
     will be equal to sum/2.
       if(sum/2 exist){
         
         1.we will check weather there is an odd element so that removing that odd element the rest sum will be also odd
           because even-odd=odd.
         2.if there is no odd element that means all elements are even 
           and in this case suppose we take an example
           n=5
           2 2 4 4 8
           we can divide it like this
           2 4 4  || 2 8
           
           so we will use a loop which will run for 15 times 
           and the inner loop will run for n times 
           and every time we will divide every element by 2 and if we find an odd element after dividing then
           we can remove that element and print it's index.
           
           why it's working?
             
           2 4 4 | 2 8
           after diving 
           1 2 2 | 1 8
           we know that if two sets are equal diving it by two also remain the same equal subset
           and we have found 1 and we will remove it and the answer is 1 now.
           it's working because every even element can be written as the sum of odd elements and thus we can 
           partiton this array into two equal halves and removing that odd elements  will cause no possibilty of
           partioning into two halves.
       }
else[
  ans=0
  }
-----------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define MOD 10000007

int sum=0,ans=0;
int arr[100];
int n;
int knapsack()
{
    int dp[n+1][sum+1];
    dp[0][0] =1;
    for(int i =1; i<=n; i++)
    {
        dp[i][0] = 1;
    }

    for(int i =1; i<=sum; i++)
    {
        dp[0][i] =0;
    }
    for(int i =1; i<=n; i++)
    {
        for(int j = 1; j<=sum; j++)
        {
            if(arr[i-1]<=j)
            {
                dp[i][j] = dp[i-1][j] ||  dp[i-1][j-arr[i-1]];
            }

            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int main()
{
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        sum=sum+arr[i];
    }
    if(sum%2)
    {
        cout<<0<<endl;
    }
    else
    {
        sum=sum/2;
        ans=knapsack();

        if(ans)
        {
            for(int j=0; j<13; j++)
            {
                bool ck=false;
                for(int i=0; i<n; i++)
                {
                    if(arr[i]%2)
                    {
                        cout<<1<<endl;
                        cout<<i+1<<endl;
                        ck=true;
                        break;
                    }
                    else
                    {
                        arr[i]=arr[i]/2;
                    }
                }
                if(ck)
                    break;
            }
        }
        else
        {
            cout<<0<<endl;
        }
    }
}


