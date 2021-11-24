/*
 * @lc app=leetcode.cn id=2006 lang=cpp
 *
 * [2006] 差的绝对值为 K 的数对数目
 */

// @lc code=start
# include <vector>
# include <algorithm>
# include <unordered_map>
using namespace std;
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> mm;
        int ans = 0;
        for (int i=0;i<nums.size();i++)
        {
            if(mm.find(nums[i]+k)!=mm.end())
            {
                ans = ans + mm[nums[i]+k];
            }
            if(mm.find(nums[i]-k)!=mm.end())
            {
                ans = ans + mm[nums[i]-k];
            }
            mm[nums[i]]++;
        }
        return ans;
    }
};
// @lc code=end

