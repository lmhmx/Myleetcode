# include<vector>
using namespace std;
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int size = nums.size();
        int min_index = 0;
        int max_index = 0;
        for (int i=0;i<size;i++)
        {
            if(nums[i]<nums[min_index])
            {
                min_index = i;
            }
            if(nums[i]>nums[max_index])
            {
                max_index = i;
            }
        }
        int ans;
        int l1=min_index+1;
        int r1 = size - min_index;
        int l2 = max_index+1;
        int r2 = size-max_index;
        int ll = max(l1,l2);
        int rr = max(r1,r2);
        int lr = l1+r2;
        int rl = r1+l2;
        return min(min(max(l1,l2),max(r1,r2)),min(lr,rl));
        
    }
};