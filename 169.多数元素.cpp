/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
# include <vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = -1;
        for (int i=0;i<nums.size();i++)
        {
            if(count==0)
            {
                candidate = nums[i];
            }
            if(candidate== nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return candidate;
    }
};
// @lc code=end

