/*
 * @lc app=leetcode.cn id=1639 lang=cpp
 *
 * [1639] 通过给定词典构造目标字符串的方案数
 */

// @lc code=start
# include <vector>
# include <string>
# include <map>
using namespace std;

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        init_col_equal(words);
        vector<vector<long long>> feasible_num(words[0].size(), vector<long long>(target.size(),0));
        long long MAX_NUM = 1000000000+7;
        for (int i=0;i<words[0].size();i++)
        {
            for (int j=0;j<=i && j < target.size();j++)
            {
                if(j==0)
                {
                    if(i==0)
                    {
                        feasible_num[i][j] = col_equal(words, target[j], i);
                    }
                    else
                    {
                        feasible_num[i][j] = feasible_num[i-1][j] + col_equal(words, target[j], i);
                    }
                }
                else
                {
                    feasible_num[i][j] = feasible_num[i-1][j] + feasible_num[i-1][j-1]*col_equal(words, target[j], i);
                }
                feasible_num[i][j] = feasible_num[i][j]%MAX_NUM;
            }
        }
        return feasible_num.back().back();
    }
private:
    void init_col_equal(vector<string>& words)
    {
        m = vector<vector<int>>(26, vector<int>(words[0].size(),0));
        int w_size = words.size();
        int w_0_size = words[0].size();
        for (int i=0;i<w_size;i++)
        {
            for (int j=0;j<w_0_size;j++)
            {
                m[words[i][j]-'a'][j]++;
            }
        }
    }
    long long col_equal(vector<string>& words, char c, int col) 
    {
        return m[c-'a'][col];
    }
private:
    vector<vector<int>> m;
};
// int main()
// {
//     Solution s;
//     string t="aba";
//     vector<string> b;
//     b.push_back("acca");
//     b.push_back("bbbb");
//     b.push_back("caca");
//     s.numWays(b,t);
//     return 0;
// }
// @lc code=end

