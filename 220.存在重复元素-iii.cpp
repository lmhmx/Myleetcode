/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
# include <vector>
# include <set>
# include <cmath>
using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long long> ms;
        if(k==0)
        {
            return false;
        }
        for (int i=0;i<nums.size();i++)
        {
            if(i==0)
            {
                ms.insert(nums[i]);
                continue;
            }
            auto low = ms.lower_bound(nums[i]);
            if(low != ms.end())
            {
                if(abs((*low)-nums[i])<=t)
                {
                    return true;
                }
                if(low !=ms.begin())
                {
                    low--;
                    if(abs((*low)-nums[i])<=t)
                    {
                        return true;
                    }
                }
            }
            else
            {
                if(abs(*ms.rbegin()-nums[i])<=t)
                {
                    return true;
                }
            }
            
            
            ms.insert(nums[i]);
            if(!(i<k))
            {
                ms.erase(nums[i-k]);
            }
        }
        return false;
    }
};
// int main()
// {
//     Solution s;
//     vector<int> a({7,1,3});
//     s.containsNearbyAlmostDuplicate(a,2,3);
//     return 0;
// }
// @lc code=end

