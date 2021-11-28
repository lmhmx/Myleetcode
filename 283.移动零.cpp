/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
# include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int none_zero_num=0;
        for (int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                nums[none_zero_num] = nums[i];
                none_zero_num++;
            }
            
        }
        for (int i=none_zero_num;i<nums.size();i++)
        {
            nums[i]=0;
        }
    }
};
// int main()
// {
//     Solution s;
//     s.moveZeroes(vector<int>()={0,1,0,3,12});
//     return 0;
// }
// @lc code=end

