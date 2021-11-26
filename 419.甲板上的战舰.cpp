/*
 * @lc app=leetcode.cn id=419 lang=cpp
 *
 * [419] 甲板上的战舰
 */

// @lc code=start
# include <vector>
using namespace std;
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        int ans = 0;
        for (int i=0;i<row;i++)
        {
            for (int j=0;j<col;j++)
            {
                if(board[i][j] == 'X')
                {
                    if(i==0 || j == 0)
                    {
                        if(i==0&&j==0)
                        {
                            ans++;
                        }
                        else if(i==0 && j!=0)
                        {
                            if(board[i][j-1]=='.')
                            {
                                ans++;
                            }
                        }
                        else
                        {
                            if(board[i-1][j] == '.')
                            {
                                ans++;
                            }
                        }
                    }
                    else
                    {
                        if(board[i-1][j]=='.'&&board[i][j-1]=='.')
                        {
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

