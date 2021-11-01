/*
 * @lc app=leetcode.cn id=1053 lang=cpp
 *
 * [1053] 交换一次的先前排列
 */

// @lc code=start
# include <string>
# include <vector>
# include <list>
# include <iostream>
# include <map>
using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        // 找到第一个i后面的比arr[i] 小的且最大的那一个
       
        
        int min_value = 500000;
        vector<int>::reverse_iterator min_iter=arr.rend();
        for (auto i=arr.rbegin();i!=arr.rend();i++){
            if(min_value >= *i){
                min_value = *i;
            }
            else{
                
                min_iter = i;
                break;
                
            }
        }
        vector<int> result = arr;
        vector<int>::reverse_iterator max_iter;
        if(min_iter != arr.rend()){
            for (auto i = arr.rbegin();i!=arr.rend();i++){
                if(*i < *min_iter){
                    for (auto j = i; j!=arr.rend();j++){
                        if(*j != *i){
                            max_iter = j-1;
                            break;
                        }
                    }
                    break;
                }
            }
            int tmp = result[(result.size()-1)-(max_iter - arr.rbegin())];
            result[(result.size()-1)-(max_iter - arr.rbegin())] = result[(result.size()-1)-(min_iter - arr.rbegin())];
            result[(result.size()-1)-(min_iter - arr.rbegin())] = tmp;
        }
        return result;
    }
};
// int main(){
//     Solution s;
//     s.prevPermOpt1(vector<int>() = {3,1,1,3});
// }
// @lc code=end

