/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start

# include<vector>
# include <algorithm>
# include <map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> ans;
        int i1=0;
        int i2 = 0;
        while(1)
        {
            if(i1==nums1.size()||i2==nums2.size())
            {
                break;
            }
            else
            {
                if(nums1[i1]==nums2[i2])
                {
                    ans.push_back(nums1[i1]);
                    i1++;
                    i2++;
                }
                else
                {
                    if(nums1[i1]<nums2[i2])
                    {
                        i1++;
                    }
                    else
                    {
                        i2++;
                    }
                }
            }
        }
        return ans;
    }   
};
// @lc code=end

