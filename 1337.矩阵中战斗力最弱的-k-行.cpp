/*
 * @lc app=leetcode.cn id=1337 lang=cpp
 *
 * [1337] 矩阵中战斗力最弱的 K 行
 */

// @lc code=start
# include <vector>
# include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<vector<int>> num;
        for (int i=0;i<mat.size();i++)
        {
            int n = 0;
            for (int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==1)
                {
                    n++;
                }
            }
            num.push_back({n,i});
        }
        stable_sort(num.begin(),num.end());
        vector<int> ans;
        for (int i=0;i<k;i++)
        {
            ans.push_back(num[i][1]);
        }
        return ans;
    }
};
// int main()
// {
//     Solution s;
//     vector<vector<int>> a;
//     a.push_back({1,0});
//     a.push_back({1,0});
//     a.push_back({1,0});
//     a.push_back({1,1});
//     s.kWeakestRows(a,4);
//     return 0;
// }
// @lc code=end

