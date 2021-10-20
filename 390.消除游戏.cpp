/*
 * @lc app=leetcode.cn id=390 lang=cpp
 *
 * [390] 消除游戏
 */

// @lc code=start
# include <string>
# include <vector>
# include <iostream>
using namespace std;
class Solution {
public:
    // 递归版
    int lastRemaining1(int n) {
        if(n==1){
            return 1;
        }
        else if(n%2==0){
            return 2*(n/2+1-lastRemaining(n/2));
        }
        else {
            return lastRemaining(n-1);
        }
    }
    // 非递归版
    int lastRemaining(int n) {
        vector<int> need_num;
        int result;
        while(1){
            if(n==1){
                break;
            }
            else if(n%2==0){
                need_num.push_back(n);
                n=n/2;
            }
            else{
                need_num.push_back(n);
                n=n-1;
            }
        }
        result = 1;
        for (auto i=need_num.rbegin();i!=need_num.rend();i++){
            if(*i % 2==0){
                result = 2*((*i)/2+1-result);
            }
            else{
                result=result;
            }
        }
        return result;
    }
};
// int main(){
//     Solution s;
//     s.lastRemaining(2);
// }
// @lc code=end

