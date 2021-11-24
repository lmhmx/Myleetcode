/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
# include<vector>
# include <algorithm>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int i=0;i<grid.size();i++)
        {
            for (int j=0;j<grid[i].size();j++)
            {
                if(i!=0 && j!=0)
                {
                    grid[i][j] = grid[i][j]+min(grid[i-1][j], grid[i][j-1]);
                }
                else
                {
                    if(i==0 && j!=0)
                    {
                        grid[i][j] = grid[i][j]+ grid[i][j-1];
                    }
                    else if(i!=0 && j==0)
                    {
                        grid[i][j] = grid[i][j] + grid[i-1][j];
                    }
                }
            }
        }
        return grid.back().back();
    }
};
// @lc code=end

