/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
# include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2)
        {
            return nums.size();
        }
        int ans = 0;
        for (int i=0;i<nums.size();i++)
        {
            if(nums[i] != nums[ans])
            {
                ans++;
                nums[ans] = nums[i];
            }
        }
        return ans+1;
    }
};
// @lc code=end

