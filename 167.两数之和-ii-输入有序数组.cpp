/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
# include <vector>
# include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int> ans;
        int re;
        for (int i=0;i<numbers.size();i++)
        {
            re=search(numbers,target-numbers[i]);
            if(re!=-1)
            {
                if(re!=i)
                {
                    ans.push_back(i);
                    ans.push_back(re);
                    break;
                }
                else
                {
                    if(i+1<numbers.size())
                    {
                        if(numbers[i]==numbers[i+1])
                        {
                            ans.push_back(i);
                            ans.push_back(i+1);
                            break;
                        }
                    }
                }
            }
        }
        ans[0]++;
        ans[1]++;
        return ans;
    }
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size();
        int mid;
        while(low<high)
        {
            mid = (low+high)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            if(nums[mid]<target)
            {
                low = mid+1;
            }
            else
            {
                high = mid;
            }
        }
        return -1;
    }
};
// @lc code=end

