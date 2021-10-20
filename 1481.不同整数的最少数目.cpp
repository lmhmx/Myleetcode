/*
 * @lc app=leetcode.cn id=1481 lang=cpp
 *
 * [1481] 不同整数的最少数目
 */

// @lc code=start
# include <string>
# include <vector>
# include <iostream>
# include <map>
# include <algorithm>
using namespace std;
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> num_size;
        for (auto i = arr.begin();i!=arr.end();i++){
            if(num_size.find(*i)==num_size.end()){
                num_size.insert({*i,1});
            }else{
                num_size.at((*i))++;
            }
        }
        int totol=0;
        int result=0;
        vector<int> size;
        for (auto i = num_size.begin();i!=num_size.end();i++){
            size.push_back((*i).second);
        }
        sort(size.begin(),size.end());
        for (auto i = size.begin();i!=size.end();i++){
            totol=totol+(*i);
            if(totol<k){
                result++;
            }
            else if(totol==k){
                result++;
                break;
            }
            else{
                break;
            }
        }
        return size.size()-result;
    }
};
// int main(){
//     Solution s;
//     vector<int>a({2,1,1,3,3,3});
//     s.findLeastNumOfUniqueInts(a,3);
// }
// @lc code=end

