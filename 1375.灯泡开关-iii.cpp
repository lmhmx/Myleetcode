/*
 * @lc app=leetcode.cn id=1375 lang=cpp
 *
 * [1375] 灯泡开关 III
 */

// @lc code=start
# include <string>
# include <vector>
# include <list>
# include <iostream>
using namespace std;
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int result = 0;
        // 初始为1，意思是从1计数
        int num = 0;
        bool* is_on=new bool[light.size()+1];
        for (int i=0;i<light.size()+1;i++){
            is_on[i]=false;
        }
        for (int i=0;i<light.size();i++){
            is_on[light[i]-1]=true;
            while(is_on[num]){
                num++;
            }
            if(num==i+1){
                result++;
            }
        }
        delete[] is_on;
        return result;
    }
};
// int main(){
//     vector<int> l={2,1,3,5,4};
//     Solution s;
//     s.numTimesAllBlue(l);
// }
// @lc code=end

