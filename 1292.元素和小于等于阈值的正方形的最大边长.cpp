/*
 * @lc app=leetcode.cn id=1292 lang=cpp
 *
 * [1292] 元素和小于等于阈值的正方形的最大边长
 */

// @lc code=start
# include<vector>
# include <algorithm>
using namespace std;
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        vector<vector<int>>& f=mat;
        int max_length = 0;
        
        for (int i=0;i<f.size();i++)
        {
            for (int j=0;j<f[i].size();j++)
            {
                if(i==0)
                {
                    if(j==0)
                    {
                        f[i][j]=mat[i][j];
                    }
                    else
                    {
                        f[i][j] = f[i][j-1]+mat[i][j];
                    }
                }
                else if(j==0)
                {
                    f[i][j] = f[i-1][j] + mat[i][j];
                }
                else
                {
                    f[i][j] = mat[i][j]+f[i-1][j]+f[i][j-1]-f[i-1][j-1];
                }
                max_length = max(max_length, max_l(f, i, j, threshold));
            }
        }
        return max_length;
    }
private:
    int max_l(vector<vector<int>>& f, int row, int col, int threshold)
    {
        int area = 0;
        int length = 0;
        for (int i=1;col-i+1>=0 && row-i+1>=0;i++)
        {
            if(row-i<0 && col - i <0)
            {
                area = f[row][col];
            }
            else if(row-i<0 )
            {
                area = f[row][col] - f[row][col-i];
            }
            else if(col-i<0)
            {
                area = f[row][col] - f[row-i][col];
            }
            else
            {
                area = f[row][col] + f[row-i][col-i] - f[row-i][col] - f[row][col-i];
            }

            if(area<=threshold)
            {
                length = i;
            }
            else
            {
                break;
            }
        }
        return length;
    }
};
// @lc code=end

