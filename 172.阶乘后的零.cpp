/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        int pow = 5;
        while(1)
        {
            if(n/pow>0)
            {
                ans = ans+n/pow;
                pow = pow*5;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

