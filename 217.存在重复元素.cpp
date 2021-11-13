/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
# include<vector>
# include<algorithm>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        vector<int> n = nums;
        sort(n.begin(),n.end());
        for (int i=0;i<n.size()-1;i++)
        {
            if(n[i]==n[i+1])
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

