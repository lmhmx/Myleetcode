/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
# include <vector>
# include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        vector<int> current = intervals[0];
        for (int i=0;i<intervals.size();i++)
        {
            if(current[1]>=intervals[i][0])
            {
                current[1] = max(current[1],intervals[i][1]);
            }
            else
            {
                ans.push_back(current);
                current = intervals[i];
            }
        }
        ans.push_back(current);
        return ans;
    }
};
// @lc code=end

