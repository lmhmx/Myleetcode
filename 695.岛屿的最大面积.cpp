/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
# include <vector>
# include <algorithm>
using namespace std;
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i=0;i<grid.size();i++)
        {
            for (int j=0;j<grid[i].size();j++)
            {
                ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
private:
    int dfs(vector<vector<int>>& grid, int sr, int sc)
    {
        if(grid[sr][sc]!=1)
        {
            return 0;
        }
        int pos[4][2];
        pos[0][0]=sr-1;
        pos[0][1]=sc;
        pos[1][0]=sr+1;
        pos[1][1]=sc;
        pos[2][0]=sr;
        pos[2][1]=sc-1;
        pos[3][0]=sr;
        pos[3][1]=sc+1;
        int row;
        int col;
        int ans = 1;

        // 防止递归到父节点
        grid[sr][sc] = 0;
        for (int i=0;i<4;i++)
        {
            row = pos[i][0];
            col = pos[i][1];
            // 如果符合坐标限制
            if(row<grid.size() && row >=0 && col < grid[0].size() && col >=0)
            {
                // 如果可以扩展，那么进行拓展
                if(grid[row][col] != 0)
                {
                    ans = ans + dfs(grid, row, col);
                }
            }
        }
        
        return ans;
    }
};
// int main()
// {
//     Solution s;
//     vector<vector<int>> a;
//     a.push_back({1,1,0,0});
//     a.push_back({1,1,0,0});
//     a.push_back({0,0,1,1});
//     a.push_back({0,0,1,1});
//     s.maxAreaOfIsland(a);
//     return 0;
// }

// @lc code=end

