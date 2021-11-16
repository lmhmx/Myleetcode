/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
# include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> row;
        for (int i=1;i<=numRows;i++)
        {
            row.clear();
            for (int c = 0;c<i;c++)
            {
                if(c == 0 || c == i-1)
                {
                    row.push_back(1);
                }
                else
                {
                    row.push_back(ans[i-2][c-1] + ans[i-2][c]);
                }
            }
            ans.push_back(row);
        }
        return ans;
    }
};
// @lc code=end

