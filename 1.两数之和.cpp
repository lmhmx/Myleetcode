/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
# include<vector>
# include <algorithm>
# include <map>
using namespace std;

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> a(2,0);
//         for (int i=0;i<nums.size();i++)
//         {
//             for (int j=i+1;j<nums.size();j++)
//             {
//                 if(nums[i]+nums[j]==target)
//                 {
//                     a[0]=i;
//                     a[1]=j;
//                     return a;
//                 }
//             }
//         }
//         return a;
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> a(2,0);
        map<int,int> num;
        for (auto& i:nums)
        {
            num[i]++;
        }
        
        for (int i=0;i<nums.size();i++)
        {
            auto re = num.find(target - nums[i]);
            if(re!=num.end())
            {
                if(re->first == nums[i] && re->second == 2)
                {
                    for (int tmp = i+1;tmp<nums.size();tmp++)
                    {
                        if(re->first==nums[tmp])
                        {
                            a[0]=i;
                            a[1]=tmp;
                            break;
                        }
                    }
                    break;
                }
                else if(re->first!=nums[i] && re->second ==1)
                {
                    for (int tmp=i+1;tmp<nums.size();tmp++)
                    {
                        if(nums[tmp]==re->first)
                        {
                            a[0]=i;
                            a[1]=tmp;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        return a;
    }
};
// int main()
// {
//     Solution s;
//     s.twoSum(vector<int>()={3,2,4},6);
//     return 0;
// }
// @lc code=end

