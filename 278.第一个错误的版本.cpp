/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
bool isBadVersion(int version)
{
    int mm =  2147483647;
    if(version<mm)
    {
        return false;
    }
    return true;
}

class Solution {
public:
    int firstBadVersion(int n) {
        long long low = 0;
        long long high = n+1L;
        long long mid;
        if(n==1)
        {
            return 1;
        }
        
        while(low<high-1)
        {
            mid = (low+high)/2;
            if(isBadVersion(mid))
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }
        return low+1;
    }
};
int main()
{
    Solution s;
    int cc = 2147483647;
    s.firstBadVersion(cc);
    return 0;
}
// @lc code=end

