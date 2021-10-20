/*
 * @lc app=leetcode.cn id=1556 lang=cpp
 *
 * [1556] 千位分隔数
 */

// @lc code=start
# include <string>
# include <vector>
# include <list>
# include <iostream>
# include <algorithm>
using namespace std;

class Solution {
public:
    string thousandSeparator(int n) {
        string s;
        int num=0;
        if(n==0){
            return "0";
        }
        while(n!=0){

            if(num%3==0 && num !=0){
                s.push_back('.');
            }
            s.push_back('0'+n%10);
            n=n/10;
            num++;
            
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
// @lc code=end

