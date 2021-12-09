/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

// @lc code=start
# include <string>
using namespace std;
class Solution {
public:
    int countSegments(string s) {
        int ans = 0;
        bool has_word_before = false;
        for (auto& c:s)
        {
            if(c==' ')
            {
                if(has_word_before)
                {
                    ans++;
                    has_word_before = false;
                }
            }
            else
            {
                has_word_before = true;
            }
        }
        if(has_word_before)
        {
            ans++;
        }
        return ans;
    }
};
// @lc code=end

