/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
 */

// @lc code=start
# include<vector>
using namespace std;
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool up;
        if(arr.size()<3)
        {
            return false;
        }
        if(arr[0]<arr[1])
        {
            up = true;
        }
        else
        {
            return false;
        }
        for (int i=1;i<arr.size()-1;i++)
        {
            if(up)
            {
                if(arr[i]>arr[i+1])
                {
                    up = false;
                }
                else if(arr[i]==arr[i+1])
                {
                    return false;
                }
            }
            else
            {
                if(!(arr[i]>arr[i+1]))
                {
                    return false;
                }
            }
        }
        if(!up)
        {
            return true;
        }
        return false;
    }
};
// @lc code=end

