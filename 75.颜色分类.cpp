/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
# include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n[3]={0};
        for (int i=0;i<nums.size();i++)
        {
            n[nums[i]]++;
        }
        for (int i=0;i<n[0];i++)
        {
            nums[i]=0;
        }
        for(int i=n[0];i<n[0]+n[1];i++)
        {
            nums[i]=1;
        }
        for (int i=n[0]+n[1];i<n[0]+n[1]+n[2];i++)
        {
            nums[i]=2;
        }
    }
};
// @lc code=end

