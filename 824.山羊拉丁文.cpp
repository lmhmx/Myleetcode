/*
 * @lc app=leetcode.cn id=824 lang=cpp
 *
 * [824] 山羊拉丁文
 */

// @lc code=start

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    string toGoatLatin(string sentence) {
        string ans;
        vector<string> v_s = split(sentence);
        for (int i=0;i<v_s.size();i++)
        {
            ans.append(Change(v_s[i],i+1));
            ans.append(" ");
        }
        ans.pop_back();
        return ans;
    }
private:
    string Change(string s, int a_size)
    {
        string ans;
        if(isAEIOU(s[0]))
        {
            ans = s;
            ans.append("ma");
        }
        else
        {
            ans.append(s.substr(1,s.size()-1));
            ans.push_back(s[0]);
            ans.append("ma");
        }
        for (int i=0;i<a_size;i++)
        {
            ans.push_back('a');
        }
        return ans;
    }
    bool isAEIOU(char c)
    {
        string s = "aeiouAEIOU";
        for (auto& ch:s)
        {
            if(ch == c)
            {
                return true;
            }
        }
        return false;
    }
    vector<string> split(string s)
    {
        vector<string> v_s;
        string tmp;
        for (int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                v_s.push_back(tmp);
                tmp.clear();
            }
            else
            {
                tmp.push_back(s[i]);
            }
        }
        if(tmp.size()>0)
        {
            v_s.push_back(tmp);
        }
        return v_s;
    }
};
// @lc code=end

