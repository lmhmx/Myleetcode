/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
# include<vector>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int mid = s.size()/2;
        int size = s.size();
        int tmp;
        for (int i=0;i<mid;i++)
        {
            tmp=s[i];
            s[i]=s[size-1-i];
            s[size-1-i]=tmp;
        }
    }
};
// @lc code=end

