/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
# include <iostream>
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i=0;i<32;i++)
        {
            if(i<16)
            {
                ans=ans|((n&(1<<i))<<(31-i-i));
            }
            else
            {
                ans = ans |((n&(1<<i))>>(i+i-31));
            }
        }
        return ans;
    }
};
// @lc code=end

