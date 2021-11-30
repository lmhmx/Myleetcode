/*
 * @lc app=leetcode.cn id=1720 lang=cpp
 *
 * [1720] 解码异或后的数组
 */

// @lc code=start
# include <vector>
using namespace std;
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans(encoded.size()+1,first);
        for (int i=1;i<ans.size();i++)
        {
            ans[i] = encoded[i-1]^ans[i-1];
        }
        return ans;
    }
};
// @lc code=end

