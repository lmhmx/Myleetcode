/*
 * @lc app=leetcode.cn id=1598 lang=cpp
 *
 * [1598] 文件夹操作日志搜集器
 */

// @lc code=start
# include <vector>
# include <string>
using namespace std;
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for (int i=0;i<logs.size();i++)
        {
            if(logs[i][0]=='.')
            {
                if(logs[i][1]=='.')
                {
                    ans = max(ans-1, 0);
                }
                else
                {
                    ans = ans;
                }
            }
            else
            {
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

