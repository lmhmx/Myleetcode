/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */

// @lc code=start
# include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if(m*n!=r*c)
        {
            return mat;
        }
        vector<vector<int>> ans(r,vector<int>(c,0));
        int cur_r = 0;
        int cur_c = 0;
        int cur_m = 0;
        int cur_n = 0;
        for (int i=0;i<r*c;i++)
        {
            cur_r = i/c;
            cur_c = i%c;
            cur_m = i/n;
            cur_n = i%n;
            ans[cur_r][cur_c] = mat[cur_m][cur_n];
        }
        return ans;
    }
};
// @lc code=end

