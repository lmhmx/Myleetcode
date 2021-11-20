/*
 * @lc app=leetcode.cn id=996 lang=cpp
 *
 * [996] 正方形数组的数目
 */

// @lc code=start
# include<vector>
# include <cmath>
# include <set>
# include <unordered_set>
# include <unordered_map>
# include <algorithm>
using namespace std;class Solution {
private:
    unordered_map<int, int> num2cnt;
    unordered_map<int, vector<int>> graph;
    
    // curr当前数字
    // 还有多少个结点需要构建，初始值为n-1
    int dfs(int curr, int rest)
    {
        // cnt 计数减1
        --num2cnt[curr];
        // 对于最后一个数字，直接返回1
        int res = 1;
        if (rest != 0) {
            // 非最后一个数字默认为0
            res = 0;
            for (int next : graph[curr])
            {
                if (num2cnt[next] > 0)
                {
                    // 递归下一个结点
                    res += dfs(next, rest - 1);
                }
            }
        }
        // 回溯
        ++ num2cnt[curr];
        return res;
    }

    bool isSqureful(int x, int y)
    {
        int r = (int)(sqrt(x+y));
        return r*r == x + y;
    }

public:
    int numSquarefulPerms(vector<int>& nums) {
        for (int num : nums)
        {
            ++num2cnt[num];
        }

        for (auto i1 = num2cnt.begin(); i1 != num2cnt.end(); ++i1)
        {
            for (auto i2 = num2cnt.begin(); i2 != num2cnt.end(); ++i2)
            {
                if (isSqureful(i1->first, i2->first))
                {
                    graph[i1->first].push_back(i2->first);
                }
            }
        }

        int res = 0;
        // 从每个点开始去计算可行路径
        int n = nums.size();
        for (auto i1 = num2cnt.begin(); i1 != num2cnt.end(); ++i1)
        {
            res += dfs(i1->first, n-1);
        }

        return res;
    }
};

// int main()
// {
//     Solution s;
//     s.numSquarefulPerms(vector<int>()={1,1,1,1,1,1,1,1,1,1,1});
//     return 0;
// }
// @lc code=end

