/*
 * @lc app=leetcode.cn id=1864 lang=cpp
 *
 * [1864] 构成交替字符串需要的最小交换次数
 */

// @lc code=start
# include <string>
# include <vector>
# include <list>
# include <iostream>
using namespace std;
class Solution {
public:
    int minSwaps(string s) {
        int one_ji=0;
        int one_ou=0;
        int zero_ji=0;
        int zero_ou=0;
        int result;
        for (int i = 0;i<s.size();i++){
            if(s[i]=='0'){
                if(i%2==0){
                    zero_ou++;
                }
                else{
                    zero_ji++;
                }
            }
            else{
                if(i%2==0){
                    one_ou++;
                }else{
                    one_ji++;
                }
            }
        }
        if(zero_ji+zero_ou==one_ji+one_ou){
            result = zero_ji<zero_ou?zero_ji:zero_ou;
        }
        else if(zero_ji+zero_ou==one_ji+one_ou+1){
            result=zero_ji;
        }else if(zero_ji+zero_ou==one_ji+one_ou-1){
            result=one_ji;
        }else{
            result=-1;
        }
        return result;
    }
};
// @lc code=end

