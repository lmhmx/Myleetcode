/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
# include <vector>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size(), target);
    }
private:
    bool search(vector<int>& nums, int low, int high, int target)
    {
        if(high-low < 3)
        {
            if(high-low < 2)
            {
                return nums[low] == target;
            }
            else
            {
                return nums[low]==target||nums[low+1]==target;
            }
        }
        if(nums[low] < nums[high-1])
        {
            return binSearch(nums, low, high, target);
        }
        int mid;
        if(high-low>1)
        {
            mid = (high+low)/2;
            bool t1;
            bool t2;
            if(nums[low]<nums[mid])
            {
                t1 = binSearch(nums, low, mid+1, target);
            }
            else
            {
                t1 = search(nums, low, mid+1,target);
            }
            if(!t1)
            {
                if(nums[mid]<nums[high-1])
                {
                    t2 = binSearch(nums, mid, high, target);
                }
                else
                {
                    t2 = search(nums, mid, high, target);
                }
            }
            return t1||t2;
        }
        else
        {
            return nums[low]==target;
        }
        
        return false;
    }
    bool binSearch(vector<int>& nums, int low, int high, int target)
    {
        int mid = (low+high)/2;
        if(nums[low]<=target && target <= nums[high-1])
        {
            while(high -low > 1)
            {
                mid = (low+high)/2;
                if(nums[mid]<target)
                {
                    low = mid;
                }
                else if(nums[mid] == target)
                {
                    return true;
                }
                else
                {
                    high = mid;
                }
            }
            return nums[low] == target;
        }
        return false;
    }
};
// int main()
// {
//     Solution s;
//     s.search(vector<int>() = {2,5,6,0,0,1,2},0);
//     return 0;
// }
// @lc code=end

