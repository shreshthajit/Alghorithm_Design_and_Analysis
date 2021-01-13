#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long
#define MOD 1000000007
using namespace std;
const int MAXN = 5e3 + 5;
int h,w,dp[MAXN][MAXN],Up_sum[MAXN][MAXN],Left_sum[MAXN][MAXN],Diagonal_sum[MAXN][MAXN];
char s[MAXN][MAXN];
signed main()
{
    scanf("%lld %lld",&h,&w);
    for(int i = 1; i <= h; i ++)
    {
        scanf("\n");
        for(int j = 1; j <= w; j ++)
            scanf("%c",&s[i][j]);
    }
    dp[1][1] = Up_sum[1][1] = Left_sum[1][1] = Diagonal_sum[1][1] = 1;
    for(int i = 1; i <= h; i ++)
    {
        for(int j = 1; j <= w; j ++)
        {
            if(i == 1 && j == 1) continue;
            if(s[i][j] == '#') continue;
            dp[i][j] += Up_sum[i - 1][j];
            dp[i][j] += Left_sum[i][j - 1];
            dp[i][j] += Diagonal_sum[i - 1][j - 1];
            Up_sum[i][j] = Up_sum[i - 1][j] + dp[i][j];
            Left_sum[i][j] = Left_sum[i][j - 1] + dp[i][j];
            Diagonal_sum[i][j] = Diagonal_sum[i - 1][j - 1] + dp[i][j];
            dp[i][j] %= MOD;
            Up_sum[i][j] %= MOD;
            Left_sum[i][j] %= MOD;
            Diagonal_sum[i][j] %= MOD;
        }
    }
    printf("%lld",dp[h][w]);
    return 0;
}
