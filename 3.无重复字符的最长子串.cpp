/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
# include <string>
# include <map>
# include <algorithm>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        map<char, int> charOfindex;
        for (int i=0;i<s.size();i++)
        {
            if(charOfindex.count(s[i]))
            {
                int charIndex = charOfindex.find(s[i])->second;
                int low = i - charOfindex.size();
                for (int j=low;j<=charIndex;j++)
                {
                    charOfindex.erase(s[j]);
                }

            }
    
            charOfindex.insert({s[i],i});
            ans = max(ans, (int)charOfindex.size());
        }
        return ans;
    }
};
// int main()
// {
//     Solution s;
//     s.lengthOfLongestSubstring("umvejcuuk");
//     return 0;
// }
// @lc code=end

