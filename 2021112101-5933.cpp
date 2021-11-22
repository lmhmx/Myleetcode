# include <vector>
# include <cmath>
# include <string>
# include <algorithm>
using namespace std;
class Solution {
public:
    long long kMirror(int k, int n) {
        long long a = 0;
        long long b = 0;
        long long ans = 0;
        int size = 0;

        a = getNext(a, 10);
        b = getNext(b, k);
            
        while(size < n)
        {
            
            if(a==b)
            {
                ans=ans+a;
                size++;
                a = getNext(a, 10);
                b = getNext(b, k);
            }
            else if(a<b)
            {
                a=getNext(a, 10);
            }
            else
            {
                b= getNext(b, k);
            }
        }
        return ans;
    }
private:
    long long getNext(long long n, int k)
    {
        long long num = n;
        long long ans;
        bool all_k_1 = true;
        vector<int> nums;
        if(num ==0)
        {
            all_k_1 = false;
            nums.push_back(0);
        }
        else
        {
            while(num!=0)
            {
                nums.push_back(num%k);
                if(num%k!=k-1)
                {
                    all_k_1 = false;
                }
                num=num/k;
            }
        }
        if(all_k_1)
        {
            ans = n+2;
        }
        else{
            if(nums.size()%2==1)
            {
                if(nums[nums.size()/2] !=k-1)
                {
                    ans = n + pow(k,nums.size()/2);
                }
                else
                {
                    int tmp = 0;
                    for(int i=0;i<nums.size()/2;i++)
                    {
                        tmp = tmp*k+nums[i];
                    }
                    tmp = tmp+1;
                    vector<int> tmp_v = toVector(tmp, k);
                    reverse(tmp_v.begin(),tmp_v.end());
                    ans = toLongLong(tmp_v)
                           + tmp * pow(k, nums.size()/2+1);
                }                
            }
            else
            {
                int tmp = 0;
                for(int i=0;i<nums.size()/2;i++)
                {
                    tmp = tmp*k+nums[i];
                }
                tmp = tmp+1;
                vector<int> tmp_v = toVector(tmp, k);
                reverse(tmp_v.begin(),tmp_v.end());
                ans = toLongLong(tmp_v)
                       + tmp * pow(k, nums.size()/2);
            }
        }
        return ans;
    }
    bool isSymmetry(const vector<int>& a)
    {
        for (int i=0;i<a.size()/2;i++)
        {
            if(a[i]!=a[a.size()-1-i])
            {
                return false;
            }
        }
        return true;
    }
    vector<int> toVector(long long n, int k)
    {
        vector<int> ans;
        if(n==0)
        {
            ans.push_back(0);
            return ans;
        }
        
        while(n!=0)
        {
            ans.push_back(n%k);
            n=n/k;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    long long toLongLong(const vector<int>& a)
    {
        long long ans= 0;
        for (int i=0;i<a.size();i++)
        {
            ans = ans*10+a[i];
        }
        return ans;
    }
};
int main()
{
    Solution s;
    s.kMirror(2,5);
    return 0;
}