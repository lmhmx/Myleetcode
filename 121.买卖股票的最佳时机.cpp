/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
# include<vector>
# include <algorithm>
# include <map>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int min_price = prices[0];
        int max_price = prices[0];
        for (int i=0;i<prices.size();i++)
        {
            if(min_price>prices[i])
            {
                min_price = prices[i];
                max_price = prices[i];
            }
            if(max_price<prices[i])
            {
                max_price = prices[i];
            }
            ans = max(ans, max_price - min_price);
        }
        return ans;
    }
};
// int main()
// {
//     Solution s;
//     s.maxProfit(vector<int>()={7,1,5,3,6,4});
//     return 0;
// }
// @lc code=end

