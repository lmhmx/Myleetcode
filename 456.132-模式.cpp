// /*
//  * @lc app=leetcode.cn id=456 lang=cpp
//  *
//  * [456] 132 模式
//  */

// // @lc code=start
// # include <string>
// # include <vector>
// # include <list>
// # include <iostream>
// # include <set>
// using namespace std;
// struct compare{
//     bool operator()(const vector<int>&a, const vector<int>& b)const{
//         if(a[0]>b[0]){
//             return true;
//         }
//         return false;
//     }
// };
// class Solution {
// public:
//     bool find132pattern(vector<int>& nums) {
//         // [low,high]
//         set<vector<int>, compare> ranges;
//         int next_min=0;
//         bool has_next_min = false;
        
//         for (int i=0;i<nums.size();i++){
//             if(ranges.size()>0){
//                 if(nums[i] >=(*ranges.begin())[1]){
//                     int tmp = ranges.rbegin()->at(0);
//                     ranges.clear();
//                     vector<int> v_t={tmp, nums[i]};
//                     ranges.insert(v_t);
//                 }
//                 else if(nums[i]<=(*ranges.rbegin())[0]){
//                     if(has_next_min){
//                         if(nums[i]<=next_min){
//                             next_min = nums[i];
//                         }
//                         else{
//                             vector<int> v_t={next_min,nums[i]};
//                             ranges.insert(v_t);
//                             has_next_min=false;
//                         }
//                     }
//                     else{
//                         next_min = nums[i];
//                         has_next_min = true;
//                     }
//                 }
//                 else{
//                     for (auto j=ranges.begin();j!=ranges.end();j++){
//                         if((*j)[0] <nums[i] && nums[i] < (*j)[1]){
//                             return true;
//                         }
//                         else if(nums[i] >= (*j)[1]){
//                             int tmp = ranges.rbegin()->at(0);
//                             auto k=j;
//                             k++;
//                             while(k!=ranges.end()){
//                                 ranges.erase(k);
//                                 k=j;
//                                 k++;
//                             }
//                             ranges.erase(j);
//                             if(has_next_min){
//                                 tmp=next_min;
//                                 has_next_min = false;
//                             }
//                             vector<int> v_t={tmp,nums[i]};
//                             ranges.insert(v_t);
//                         }
//                     }
//                 }
//             }
//             else{
//                 if(has_next_min){
//                     if(next_min<nums[i]){
                        
//                         vector<int> v_t={next_min,nums[i]};
//                         ranges.insert(v_t);
//                         has_next_min = false;
//                     }
//                     else{
//                         next_min=nums[i];
//                     }
//                 }
//                 else{
//                     next_min=nums[i];
//                     has_next_min=true;
//                 }
//             }
//         }
//     return false;
//     }

    
// };
// int main(){
//     Solution s;
//     vector<int> v={1,2,3,4,-4,-3,-5,-1};
//     cout << s.find132pattern(v);
// }
# include <vector>
# include <set>
# include <iostream>
using namespace std;
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }

        // 左侧最小值
        int left_min = nums[0];
        // 右侧所有元素
        multiset<int> right_all;

        for (int k = 2; k < n; ++k) {
            right_all.insert(nums[k]);
        }

        for (int j = 1; j < n - 1; ++j) {
            if (left_min < nums[j]) {
                auto it = right_all.upper_bound(left_min);
                if (it != right_all.end() && *it < nums[j]) {
                    return true;
                }
            }
            left_min = min(left_min, nums[j]);
            right_all.erase(right_all.find(nums[j + 1]));
        }

        return false;
    }
};
// int main(){
//     Solution s;
//     vector<int> v={100,1,2,98,99,96,97};
//     cout << s.find132pattern(v);
// }
// // @lc code=end
