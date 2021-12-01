/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
# include <vector>
using namespace std;
// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         if(nums.size()==1)
//         {
//             return 0;
//         }
//         else if(nums.size()==2)
//         {
//             return nums[0]>nums[1]?0:1;
//         }
//         if(nums[0]>nums[1])
//         {
//             return 0;
//         }
//         else if(nums[nums.size()-1]>nums[nums.size()-2])
//         {
//             return nums.size()-1;
//         }
//         int low = 1;
//         int high = nums.size()-2;
//         int mid;
//         while(low < high)
//         {
//             mid = (low+high)/2;
//             if(nums[low]<nums[mid])
//             {

//             }
//         }
//     }
// };
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        // 辅助函数，输入下标 i，返回一个二元组 (0/1, nums[i])
        // 方便处理 nums[-1] 以及 nums[n] 的边界情况
        auto get = [&](int i) -> pair<int, int> {
            if (i == -1 || i == n) {
                return {0, 0};
            }
            return {1, nums[i]};
        };

        int left = 0, right = n - 1, ans = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (get(mid - 1) < get(mid) && get(mid) > get(mid + 1)) {
                ans = mid;
                break;
            }
            if (get(mid) < get(mid + 1)) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

// @lc code=end

