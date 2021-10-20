/*
 * @lc app=leetcode.cn id=1277 lang=cpp
 *
 * [1277] 统计全为 1 的正方形子矩阵
 */

// @lc code=start
# include <string>
# include <vector>
# include <list>
# include <iostream>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int num=0;
        int row = matrix.size();
        int col = matrix[0].size();
        int** f=new int*[matrix.size()];
        for (int i=0;i<matrix.size();i++){
            f[i]=new int[matrix[i].size()];
        }
        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                f[i][j]=0;
            }
        }
        for(int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                if(i==0||j==0){
                    f[i][j]=matrix[i][j]==1?1:0;
                }
                else if(matrix[i][j] == 0){
                    f[i][j]=0;
                }
                else {
                    f[i][j]=1+min3(f[i-1][j-1],f[i-1][j],f[i][j-1]);
                }
            }
        }
        for(int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                num=num+f[i][j];
            }
        }
        for(int i=0;i<row;i++){
            delete[] f[i];
        }
        delete[] f;
        return num;
    }
private:
    int min3(int a, int b, int c){
        int t=a<b?a:b;
        return c<t?c:t;
    }
};
// @lc code=end

