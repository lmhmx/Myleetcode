/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
# include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool ans = false;
        for (int i=0;i<matrix.size();i++)
        {
            if(binSearch(matrix[i], target))
            {
                ans = true;
                break;
            }
        }
        return ans;
    }
private:
    bool binSearch(const vector<int>& a, int target)
    {
        if(a.size()==0)
        {
            return false;
        }

        bool ans = false;
        int low = 0;
        int high = a.size();
        int mid;
        while(low < high)
        {
            mid = (low+high)/2;
            if(a[mid]>target)
            {
                high = mid;
            }
            else if(a[mid] == target)
            {
                ans = true;
                break;
            }
            else
            {
                low = low < mid?mid:low+1;
            }
        }
        return ans;
    }
};
// @lc code=end

