/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
# include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // if(image[sr][sc] == newColor)
        // {
        //     return image;
        // }
        dfs(image, sr, sc, newColor);
        return image;
    }
private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
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
        for (int i=0;i<4;i++)
        {
            row = pos[i][0];
            col = pos[i][1];
            // 如果符合坐标限制
            if(row<image.size() && row >=0 && col < image[0].size() && col >=0)
            {
                // 如果可以扩展，那么进行拓展
                if(image[row][col] == image[sr][sc])
                {
                    //防止递归到父节点
                    image[sr][sc]--;
                    dfs(image, row, col, newColor);
                    image[sr][sc]++;
                }
            }
        }
        image[sr][sc] = newColor;
    }
};
// @lc code=end

