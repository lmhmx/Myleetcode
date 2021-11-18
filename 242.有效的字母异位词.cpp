/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
# include <string>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        int ransom_num[26];
        int magazine_num[26];
        for (int i=0;i<26;i++)
        {
            ransom_num[i]=0;
            magazine_num[i]=0;
        }
        for (int i=0;i<s.size();i++)
        {
            ransom_num[s[i]-'a']++;
        }
        for (int i=0;i<t.size();i++)
        {
            magazine_num[t[i]-'a']++;
        }
        for (int i=0;i<26;i++)
        {
            if(ransom_num[i]!=magazine_num[i])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

