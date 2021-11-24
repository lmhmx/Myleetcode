/*
 * @lc app=leetcode.cn id=1452 lang=cpp
 *
 * [1452] 收藏清单
 */

// @lc code=start
# include<vector>
# include<string>
# include <unordered_map>
# include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        vector<int> ans;
        unordered_map<string, int> com;
        int num = 0;
        vector<vector<int>> favor;
        for (auto& i:favoriteCompanies)
        {
            favor.push_back(vector<int>());
            for (auto& j:i)
            {
                if(com.find(j)==com.end())
                {
                    com.insert({j,num});
                    num++;
                }
                favor.back().push_back(com[j]);
            }
            sort(favor.back().begin(),favor.back().end());
        }
        for (int i=0;i<favor.size();i++)
        {
            bool isBelong = false;
            for (int j=0;j<favor.size();j++)
            {
                if(trueBelong(favor[i],favor[j]))
                {
                    isBelong = true;
                    break;
                }
            }
            if(!isBelong)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
private:
    bool trueBelong(vector<int>& a, vector<int>& b)
    {
        // a \in b? 
        if(a.size()>=b.size())
        {
            return false;
        }
        int i=0;
        int j=0;
        while(i<a.size()&&j<b.size())
        {
            if(a[i]==b[j])
            {
                i++;
                j++;
            }
            else if(a[i]<b[j])
            {
                return false;
            }
            else
            {
                j++;
            }
        }
        if(i == a.size())
        {
            return true;
        }
        return false;
    }
};
// @lc code=end

