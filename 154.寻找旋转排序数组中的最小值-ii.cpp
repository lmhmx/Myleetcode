/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II

*/

// @lc code=start
# include <iostream>
# include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        // int ans = nums[0];
        // for (int i=0;i<nums.size();i++){
        //     if(ans>nums[i])
        //     {
        //         ans = nums[i];
        //     }
        // }
        // return ans;
        return findMin(nums,0,nums.size());
    }
private:
    int findMin(vector<int>& nums, int low, int high)
    {
        if(nums[low]<nums[high-1]){
            return nums[low];
        }
        int left = low;
        int right = high;
        int mid;
        while(1)
        {
            mid = (left+right)/2;
            if(right-left<3)
            {
                return min(nums[left],nums[mid]);
            }
            if(nums[left] < nums[right-1])
            {
                return nums[left];
            }
            if(nums[left]<nums[mid])
            {
                left = mid+1;
            }
            else if(nums[left] > nums[mid])
            {
                right = mid+1;
            }
            else
            {
                int t1 = findMin(nums,left,mid);
                int t2 = findMin(nums,mid,right);
                return min(t1,t2);
            }
            
        }
    }
};
// int main()
// {
//     Solution s;
//     int a =s.findMin(vector<int>()={4,5,6,7,0,1,2});
//     return 0;
// }
// @lc code=end

