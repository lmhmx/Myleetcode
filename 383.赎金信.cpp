/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
# include <string>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ransom_num[26];
        int magazine_num[26];
        for (int i=0;i<26;i++)
        {
            ransom_num[i]=0;
            magazine_num[i]=0;
        }
        for (int i=0;i<ransomNote.size();i++)
        {
            ransom_num[ransomNote[i]-'a']++;
        }
        for (int i=0;i<magazine.size();i++)
        {
            magazine_num[magazine[i]-'a']++;
        }
        for (int i=0;i<26;i++)
        {
            if(ransom_num[i]>magazine_num[i])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

