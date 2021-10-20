/*
 * @lc app=leetcode.cn id=1392 lang=cpp
 *
 * [1392] 最长快乐前缀
 */

// @lc code=start
# include <string>
# include <vector>
# include <list>
# include <iostream>
using namespace std;
// Rabin-Karp算法 
// class Solution {
// public:
//     string longestPrefix(string s) {
//         int n = s.size();
//         int prefix = 0, suffix = 0;
//         int base = 31, mod = 1000000007, mul = 1;
//         int happy = 0;
//         for (int i = 1; i < n; ++i) {
//             prefix = ((long long)prefix * base + (s[i - 1] - 97)) % mod;
//             suffix = (suffix + (long long)(s[n - i] - 97) * mul) % mod;
//             if (prefix == suffix) {
//                 happy = i;
//             }
//             mul = (long long)mul * base % mod;
//         }
//         return s.substr(0, happy);
//     }
// };
class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> fail(n, -1);
        for (int i = 1; i < n; ++i) {
            int j = fail[i - 1];
            while (j != -1 && s[j + 1] != s[i]) {
                j = fail[j];
            }
            if (s[j + 1] == s[i]) {
                fail[i] = j + 1;
            }
        }
        return s.substr(0, fail[n - 1] + 1);
    }
};

// int main(){
//     Solution s;
//     s.longestPrefix("ababab");
//     return 0;
// }
// @lc code=end

