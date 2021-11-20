/*
 * @lc app=leetcode.cn id=996 lang=cpp
 *
 * [996] 正方形数组的数目
 */

// @lc code=start
# include<vector>
# include <cmath>
# include <set>
# include <unordered_set>
# include <algorithm>
using namespace std;
class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) 
    {

        sort(nums.begin(),nums.end());
        set<vector<int>, cmp> mm;
        vector<int> index(nums.size(),0);
        for (int i=0;i<index.size();i++)
        {
            index[i] = i;
        }
        vector<int> nums_last(nums.size(),0);
        vector<int> nums_cur(nums);
        int ans = 0;
        while(1)
        {
            getIndexOrder(nums, nums_cur, index);
            if(equal(nums_last, nums_cur))
            {
                if(nextIndex(index))
                {
                    continue;
                }
                else
                {
                    break;
                }
                continue;
            }
            else
            {
                nums_last = nums_cur;
            }
            if(check(nums_cur))
            {
                if(mm.count(nums_cur)==0)
                {
                    ans++;
                    mm.insert(nums_cur);
                }
            }
            if(nextIndex(index))
            {
                continue;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
private:
    void getIndexOrder(vector<int>& nums, vector<int>& nums_cur, vector<int>& index)
    {
        for (int i=0;i<nums.size();i++)
        {
            nums_cur[i] = nums[index[i]];
        }
    }
    bool equal(vector<int>& n1, vector<int>& n2)
    {
        for (int i=0;i<n1.size();i++)
        {
            if(n1[i] !=n2[i])
            {
                return false;
            }
        }
        return true;
    }
    bool check(vector<int>& nums)
    {
        int sum = 0;
        int ss = 0;
        for (int i=0;i<nums.size()-1;i++)
        {
            sum = nums[i]+nums[i+1];
            ss = sqrt((double)sum);
            if(sum!=ss*ss)
            {
                return false;
            }
        }
        return true;
    }
    bool nextIndex(vector<int>& index)
    {
        for (int i=index.size()-1;i>=1;i--)
        {
            if(index[i]>index[i-1])
            {
                int min_index = i;
                for (int j=i;j<index.size();j++)
                {
                    if(index[i-1] < index[j] && index[j] < index[min_index])
                    {
                        min_index = j;
                    }
                }
                swap(index[min_index],index[i-1]);
                sort(index.begin()+i,index.end());
                return true;
            }
        }
        return false;
    }
private:
    struct cmp
    {
        bool operator()(const vector<int>& a, const vector<int>& b)const
        {
            for (int i=0;i<a.size();i++)
            {
                if(a[i]<b[i])
                {
                    return true;
                }
                else if(a[i]>b[i])
                {
                    return false;
                }
            }
            return false;
        }
    };
};
// int main()
// {
//     Solution s;
//     s.numSquarefulPerms(vector<int>()={1,1,1,1,1,1,1,1,1,1,1});
//     return 0;
// }
// @lc code=end

