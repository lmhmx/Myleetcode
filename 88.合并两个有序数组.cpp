/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
# include<vector>
# include <algorithm>
# include <map>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp = nums1;
        int n1=0;
        int n2 = 0;
        for (int i=0;i<m+n;i++)
        {
            if(n1<m && n2<n)
            {
                if(tmp[n1]>nums2[n2])
                {
                    nums1[i] = nums2[n2];
                    n2++;
                }
                else
                {
                    nums1[i] = tmp[n1];
                    n1++;
                }
            }
            else
            {
                if(n1==m)
                {
                    nums1[i] = nums2[n2];
                    n2++;
                }
                else
                {
                    nums1[i] = tmp[n1];
                    n1++;
                }
            }
        }
        
    }
};
// @lc code=end

