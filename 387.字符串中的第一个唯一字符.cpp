/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
# include <string>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        int c[26];
        for (int i=0;i<26;i++)
        {
            c[i] = 0;
        }
        for (int i=0;i<s.size();i++)
        {
            c[s[i]-'a']++;
        }
        for (int i=0;i<s.size();i++)
        {
            if(c[s[i]-'a']==1)
            {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

