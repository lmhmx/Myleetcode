/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
# include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_p = prices[0];
        int ans = 0;
        for (int i=0;i<prices.size();i++)
        {
            ans= max(ans, prices[i] - min_p);
            min_p = min(min_p, prices[i]);
        }
        return ans;

    }
};
// @lc code=end

