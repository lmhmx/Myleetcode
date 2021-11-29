/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
# include <vector>
# include <string>
# include <map>
# include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       
        map<string,vector<string>> mp;
        string s;
        for (int i=0;i<strs.size();i++)
        {
            s=strs[i];
            sort(s.begin(),s.end());
            mp[s].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for (auto i=mp.begin();i!=mp.end();i++)
        {
            ans.push_back(i->second);
        }
        return ans;
    }
};
// @lc code=end

