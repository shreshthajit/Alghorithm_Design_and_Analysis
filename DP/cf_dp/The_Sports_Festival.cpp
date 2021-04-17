We need to find the sum of difference between min and max in the range 1 to i for every i.

suppose the array is not sorted.then if we want to find the dif of min and max in the range 1 and n-1 we can see that
the nth value can be the maxium or the minimum of the whole array.If it is not the max and min of the whole array then 
the difference will be maximum in the range 1 to n-1. SO the best strategy is to sort the array and 
every time we will the first and last element's difference and take the min of l to r-1 and l+1 to r. this means we are checking
both from the left and right and taking the minvalue which will minimize the sum.

-----------------------------------------------------------------------

#include<bits/stdc++.h>

using namespace std;
const int MAX = 2e3 + 5;

long long dp[MAX][MAX],a[MAX];
long long  recursive_dp(long long  l,long long  r)
{
    if(dp[l][r]!=-1)
    {
        return dp[l][r];
    }
    if(l==r)
        return 0;

    return dp[l][r]=a[r]-a[l]+min(recursive_dp(l,r-1),recursive_dp(l+1,r));
}

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    sort(a,a+n);
    cout<<recursive_dp(0,n-1)<<endl;
}
 
