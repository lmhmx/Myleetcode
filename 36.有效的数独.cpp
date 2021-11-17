/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool* nine = new bool[9];

        // 横着
        for (int i=0;i<9;i++)
        {
            reset(nine);
            for (int j=0;j<9;j++)
            {
                int tmp = board[i][j]-'1';
                if(tmp<=9 && tmp >= 0)
                {
                    if(nine[tmp])
                    {
                        return false;
                    }
                    nine[tmp] = true;
                }
                
            }
        }

        // 竖着
        for (int i=0;i<9;i++)
        {
            reset(nine);
            for (int j=0;j<9;j++)
            {
                int tmp = board[j][i]-'1';
                if(tmp<=9 && tmp >= 0)
                {
                    if(nine[tmp])
                    {
                        return false;
                    }
                    nine[tmp] = true;
                }
            }
        }
        for (int i=0;i<3;i++)
        {
            reset(nine);
            for (int j=0;j<3;j++)
            {
                reset(nine);
                if(!check(board,i,j,nine))
                {
                    return false;
                }
            }
        }
        delete[] nine;
        return true;
    }
private:
    bool check(vector<vector<char>>& board, int i,int j, bool* nine)
    {
        for (int ii =0;ii<3;ii++)
        {
            for (int jj=0;jj<3;jj++)
            {
                int tmp = board[i*3+ii][j*3+jj]-'1';
                if(tmp<=9 && tmp >= 0)
                {
                    if(nine[tmp])
                    {
                        return false;
                    }
                    nine[tmp] = true;
                }
            }
            
        }
        return true;
    }
    void reset(bool* nine)
    {
        for (int i=0;i<9;i++)
        {
            nine[i]=false;
        }
    }
};
// @lc code=end
