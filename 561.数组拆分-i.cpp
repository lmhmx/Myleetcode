/*
 * @lc app=leetcode.cn id=561 lang=cpp
 *
 * [561] 数组拆分 I
 */

// @lc code=start
# include <algorithm>
# include <vector>
using namespace std;
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        for (int i=0;i<nums.size()/2;i++)
        {
            ans = ans + nums[2*i];
        }
        return ans;
    }
};
// @lc code=end

