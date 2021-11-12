/*
 * @lc app=leetcode.cn id=1888 lang=cpp
 *
 * [1888] 使二进制字符串字符交替的最少反转次数
 */

// @lc code=start
# include <string>
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
class Solution {
public:
    int minFlips(string s) {
        int len = s.size();
        string target = "01";

        int cnt = 0;
        for (int i = 0; i < len; i++) {
            cnt += (s[i] != target[i % 2]);
        }

        //s += s;
        int ans = min({ cnt, len - cnt });
        for (int i = 0; i < len; i++) {
            cnt -= (s[i] != target[i % 2]);
            cnt += (s[i] != target[(i + len) % 2]);
            ans = min({ ans, cnt, len - cnt });
        }

        return ans;
    }
};
// @lc code=end

