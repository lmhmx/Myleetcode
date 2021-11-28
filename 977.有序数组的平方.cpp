/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
# include <iostream>
# include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> v_1;
        vector<int> v_2;
        for (int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                v_1.push_back(nums[i]*nums[i]);
            }
            else
            {
                v_2.push_back(nums[i]*nums[i]);
            }
        }
        vector<int> ans(nums.size(),0);
        int i1 = v_1.size()-1;
        int i2 = 0;
        for (int i=0;i<nums.size();i++)
        {
            if(i1>=0)
            {
                if(i2<v_2.size())
                {
                    if(v_1[i1]<v_2[i2])
                    {
                        ans[i] = v_1[i1];
                        i1--;
                    }
                    else
                    {
                        ans[i] = v_2[i2];
                        i2++;
                    }
                }
                else
                {
                    ans[i] = v_1[i1];
                    i1--;
                }
            }
            else
            {
                ans[i]=v_2[i2];
                i2++;
            }
        }
        return ans;
    }
};
// @lc code=end

