/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
# include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n,0));
        int row = 0;
        int col = 0;
        int num = 1;
        while(num<=n*n)
        {
            v[row][col] = num;
            num++;
            
            if(row - 1 <= col && col+row < n-1)
            {
                col++;
            }
            else if(row < col && col + row >=n-1)
            {
                row++;
            }
            else if(col<=row && col + row >= n)
            {
                col--;
            }
            else if(col < row && col + row <= n-1)
            {
                row--;
            }
            else
            {
                // do nothing
            }
        }
        
        return v;
    }
};
// int main()
// {
//     Solution s;
//     s.generateMatrix(3);
//     return 0;
// }
// @lc code=end

