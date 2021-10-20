/*
 * @lc app=leetcode.cn id=1189 lang=cpp
 *
 * [1189] “气球” 的最大数量
 */

// @lc code=start
# include <string>
# include <vector>
# include <list>
# include <iostream>
using namespace std;
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int nums[26]={0};
        for (auto & c: text){
            nums[c-'a']++;
        }
        return min5(nums['a'-'a'],nums['b'-'a'],nums['l'-'a']/2,nums['n'-'a'], nums['o'-'a']/2);
    }
private:
    int min5(int a, int b, int c, int d,int e){
        int t=a;
        t=t<b?t:b;
        t=t<c?t:c;
        t=t<d?t:d;
        t=t<e?t:e;
        return t;
    }
};
// @lc code=end

