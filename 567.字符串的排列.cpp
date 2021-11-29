/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
# include <iostream>
# include <vector>
# include<string>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1_c[26]={0};
        int s2_c[26]={0};
        for (auto& a:s1)
        {
            s1_c[a-'a']++;
        }
        for (int i=0;i<s2.size();i++)
        {
            if(i<s1.size())
            {
                s2_c[s2[i]-'a']++;
            }
            else
            {
                s2_c[s2[i-s1.size()]-'a']--;
                s2_c[s2[i]-'a']++;
            }
            if(equal(s1_c,s2_c))
            {
                return true;
            }
        }
        return false;
    }
private:
    bool equal(int* a, int* b)
    {
        for (int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

