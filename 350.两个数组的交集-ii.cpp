/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
# include<vector>
# include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int p1=0;
        int p2=0;
        while(1)
        {
            if(nums1[p1]==nums2[p2])
            {
                ans.push_back(nums1[p1]);
                p1++;
                p2++;
            }
            else if(nums1[p1]<=nums2[p2])
            {
                p1++;
            }
            else
            {
                p2++;
            }
            if(p1 == nums1.size()||p2 == nums2.size())
            {
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

