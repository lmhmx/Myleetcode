/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
# include <vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1,1);
        // 初始值是C_n_0 = 1
        // C_n_i = C_n_(i-1)*(n-i+1)/i
        long long C_n_i = 1;
        int n = rowIndex;
        for (int i=1;i<=rowIndex;i++)
        {
            C_n_i = C_n_i*(n-i+1)/i;
            ans[i] = C_n_i;
        }
        return ans;
    }
};
// @lc code=end

