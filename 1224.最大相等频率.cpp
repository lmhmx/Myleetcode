/*
 * @lc app=leetcode.cn id=1224 lang=cpp
 *
 * [1224] 最大相等频率
 */

// @lc code=start
# include <vector>
# include <string>
# include <iostream>
# include <map>

using namespace std;
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        map<int,int> num_num;
        map<int, int> num_num_num;
        int ans;
        for (int i=0;i<nums.size();i++)
        {
            if(num_num.find(nums[i])==num_num.end())
            {
                num_num.insert({nums[i],1});
                
            }
            else
            {
                num_num[nums[i]]++;
                
            }

            int newNum = num_num[nums[i]];
            int oldNum = newNum-1;
            if(num_num_num.find(newNum) != num_num_num.end())
            {
                num_num_num[newNum]++;
            }
            else
            {
                num_num_num.insert({newNum,1});
            }
            if(oldNum!=0)
            {
                if(num_num_num[oldNum] == 1)
                {
                    num_num_num.erase(num_num_num.find(oldNum));
                }
                else
                {
                    num_num_num[oldNum]--;
                }
            }
            
            if(num_num_num.size()==1)
            {
                // 所有出现过的数字出现的次数都一样
                if(num_num_num.begin()->first == 1)
                {
                    ans = i+1;
                }
                else if(num_num_num.begin()->second == 1)
                {
                    ans = i+1;
                }
            }
            else if(num_num_num.size()==2)
            {
                int key_1=num_num_num.begin()->first;
                int v_1 = num_num_num.begin()->second;
                int key_2=num_num_num.rbegin()->first;
                int v_2 = num_num_num.rbegin()->second;
                if(v_1==1||v_2==1)
                {
                    if(v_1==1&& key_1==1)
                    {
                        ans=i+1;
                    }
                    else if(v_2==1 && key_2==1)
                    {
                        ans=i+1;
                    }
                    else if(v_1 == 1 &&  key_1-key_2==1)
                    {
                        ans=i+1;
                    }
                    else if(v_2 == 1 &&  key_2-key_1==1)
                    {
                        ans=i+1;
                    }
                }
            }
        }
        return ans;
    }
};
// int main()
// {
//     Solution s;
//     cout << s.maxEqualFreq(vector<int>() = {10,2,8,9,3,8,1,5,2,3,7,6});
//     return 0;
// }
// @lc code=end

