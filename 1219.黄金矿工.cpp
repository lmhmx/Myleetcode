/*
 * @lc app=leetcode.cn id=1219 lang=cpp
 *
 * [1219] 黄金矿工
 */

// @lc code=start
# include <vector>
# include <algorithm>
using namespace std;
class Solution {
private:
    // 四个方向
    int dires[5] = {1, 0, -1 , 0, 1};

    // 地图大小
    int rows;
    int cols;

    int dfs(int x, int y, vector<vector<int>>& grid)
    {
        if (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] > 0)
        {
            int curr = grid[x][y];
            int maxNext = 0;
            grid[x][y] = 0;
            // 四个方向去遍历
            for (int i = 0; i < 4; ++i)
            {
                maxNext = max(maxNext, dfs(x+dires[i], y+dires[i+1], grid));
            }
            // 回溯
            grid[x][y] = curr;
            return curr + maxNext;
        }
        else
        {
            return 0;
        }
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int res = 0;
        // 从每个起点出发取找最大黄金数量
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                res = max(res, dfs(i, j, grid));
            }
        }
        return res;
    }
};
// @lc code=end

