
1.Here dp state is dp[N][k][2] which represents the number of particle from plate N when age is k and state is either 0 or 1.
 if dir ==0 then the copy ray is moving to thata direction else the original ray is moving to that direction
#include<bits/stdc++.h>
using namespace std;

const int N = 1001;
const int K = 1001;

int n, k;
const int mod = 1e9 + 7;

int dp[N][K][2];

int solve(int curr, int k, int dir)
{
    if (k == 1)//if age is 1 then we can't make an other particle from it so it is the base condition of this dp.
    {
        return 1;
    }

    if (dp[curr][k][dir] != -1)//if it has precalculated value then return that value.
    {
        return dp[curr][k][dir];
    }
    int ans = 2;

    if (dir == 1)//if the current ray is moving towards right
    {
        if (curr < n)//if current plate is not the last plate becuase every plate will use this ray to create another by going right.
        {
            ans += solve(curr + 1, k, dir) - 1;//here we have subtracted 1 because we don't want to count the same ray  more than one
          ///here the value of k is not changing because the same ray from the fast plate is moving to the right as per the picture
        }
        ans %= mod;



        if (curr > 1)///if the ray is moving towards left as it will hit the left plate so we need to move left.
         /// curr>1 because if the ray is hitting on plate 1 then we can't go left.
        {
            ans += solve(curr - 1, k - 1, 1 - dir) - 1;//here k is decreasing as per the picture  and the ray is moving towards left
        }

        ans %= mod;
        dp[curr][k][dir] = ans;
    }
    else
    {
        if (curr > 1)//if we are moving left and the ray is hitting the left plate then plate number is decreasing and the same ray
          // is moving toward left so the value of k is not decreasing
            ans += solve(curr - 1, k, dir) - 1;

        ans %= mod;

        if (curr < n)//if the ray is moving towards right then the copy ray's age will decrease as here k is decreasing and the value
          //of plate is increasing
            ans += solve(curr + 1, k - 1, 1 - dir) - 1;

        ans %= mod;
        dp[curr][k][dir] = ans;
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        memset(dp, -1, sizeof(dp));
        cout << solve(1, k, 1) << endl;
    }
}
