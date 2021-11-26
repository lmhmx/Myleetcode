/*
 * @lc app=leetcode.cn id=1434 lang=cpp
 *
 * [1434] 每个人戴不同帽子的方案数
 */

// @lc code=start
# include <vector>
# include <map>
# include <unordered_map>
using namespace std;
class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        int len = hats.size();
        int status = 1<<len;
        vector<int> dp(status, 0);
        dp[0] = 1;
        unordered_map<int, vector<int>> hat2person; // 攻防转换，我们要的是每顶帽子可以戴给谁
        for(int i=0; i<len; i++){
            for(int j: hats[i]) {
                hat2person[j].push_back(i);
            }
        }
        for(auto& p: hat2person){ // 遍历每个帽子
            for (int i = status - 1; i >= 0; i--) { // 熟悉的0-1背包循环
                for(int person: p.second) { 
                 // 遍历当前帽子可以分配的人，如果他头上有帽子，那么我们可以把他的帽子取下来，相当于将物品从背包里拿出
                    int personbit = 1 << person;
                    if (i & (personbit)) {
                        dp[i] += dp[i - personbit];
                        dp[i] %= 1000000007;
                    }
                }
            }
        }
        return dp[status-1];
    }
};
int main()
{
    Solution s;
    
    vector<int> b;
    for (int i=0;i<40;i++)
    {
        b.push_back(i+1);
    }
    vector<vector<int>> a(10,b);
    s.numberWays(a);
    return 0;
}
// @lc code=end

