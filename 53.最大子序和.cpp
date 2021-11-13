/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
# include<vector>
# include<algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0;
        int ans = nums[0];
        for(int i=0;i<nums.size();i++)
        {
            pre = max(pre+nums[i],nums[i]);
            ans = max(ans,pre);
        }
        return ans;
    }
};
// @lc code=end

