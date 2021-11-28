# include<vector>
using namespace std;
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less = 0;
        int equal = 0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == target)
            {
                equal++;
            }
            else if(nums[i] < target)
            {
                less++;
            }
        }
        for (int i=less;i<less+equal;i++)
        {
            ans.push_back(i);
        }
        return ans;
    }
};