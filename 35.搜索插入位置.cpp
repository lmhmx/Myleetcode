/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
# include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = -1;
        int high = nums.size();
        int mid;
        while(low<high-1)
        {
            mid = (low+high)/2;
            if(nums[mid]<target)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
        return low+1;
    }
};
// @lc code=end

