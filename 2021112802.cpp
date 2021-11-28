# include <iostream>
# include <vector>
using namespace std;
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans;
        long long sum = 0;
        for (int i=0;i<nums.size();i++)
        {
            if(i-k<0)
            {
                ans.push_back(-1);
                sum = sum+nums[i];
            }
            else if(i+k>=nums.size())
            {
                ans.push_back(-1);
            }
            else
            {
                if(i-k-1<0)
                {
                    for (int j=i;j<i+k;j++)
                    {
                        sum = sum+nums[j];
                    }
                    sum = sum+nums[i+k];
                }
                else
                {
                    sum = sum+nums[i+k]-nums[i-k-1];
                }
                ans.push_back(sum/(2*k+1));
            }
        }
        return ans;
    }
};