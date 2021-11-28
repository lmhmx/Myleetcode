/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
# include <vector>
# include <map>
using namespace std;
class Solution {
public:    
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int,int> mp;
        vector<vector<int>> ans;
        for (int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        // 排除三个0
        if(mp.count(0))
        {
            if(mp[0]>=3)
            {
                ans.push_back({0,0,0});
            }
        }
        // 排除两个相同的
        for (auto& m:mp)
        {
            if(m.second>=2)
            {
                if(m.first != 0)
                {
                    if(mp.count(-2*m.first))
                    {
                        ans.push_back({m.first,m.first,-2*m.first});
                    }
                }
            }
        }
        // 三个都是不一样的
        for (auto a=mp.begin();a!=mp.end();a++)
        {
            auto b = a;
            b++;
            for (;b!=mp.end();b++)
            {
                auto c = mp.find(-(a->first+b->first));
                if(c!=mp.end())
                {
                    if(b->first<c->first)
                    {
                        ans.push_back({a->first,b->first,c->first});
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

