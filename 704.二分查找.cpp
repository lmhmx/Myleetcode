/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
# include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size();
        int mid;
        while(low<high)
        {
            mid = (low+high)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            if(nums[mid]<target)
            {
                low = mid+1;
            }
            else
            {
                high = mid;
            }
        }
        return -1;
    }
};
// @lc code=end

