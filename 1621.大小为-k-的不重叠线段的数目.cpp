/*
 * @lc app=leetcode.cn id=1621 lang=cpp
 *
 * [1621] 大小为 K 的不重叠线段的数目
 */

// @lc code=start
# include <string.h>
class Solution {
public:
    int numberOfSets(int n, int k) {
        long dp[n+1][k+1];
        long sum[n+1][k+1];
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
        for(int i = 1;i<=n;i++)
        {
            dp[i][0] = 1;
        }
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=k;j++)
            {
                sum[i][j-1] = sum[i-1][j-1]+dp[i-1][j-1];
                sum[i][j] %=1000000007;
                dp[i][j] += sum[i][j-1] + dp[i-1][j];
                dp[i][j] %= 1000000007;
            }
        }
        return dp[n][k];
    }
};

// int main()
// {
//     Solution s;
//     s.numberOfSets(30,7);
//     return 0;
// }

// @lc code=end

