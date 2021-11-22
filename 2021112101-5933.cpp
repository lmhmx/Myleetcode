# include <vector>
# include <cmath>
# include <string>
# include <map>
# include <algorithm>
using namespace std;
class Solution {
public:
    long long kMirror(int k, int n) {
        long long a = 0;
        long long ans = 0;
        int size = 0;
        while(size < n)
        {
            a = getNext(a);
            if(isSymmetry(toVector(a,k)))
            {
                ans=ans+a;
                size++;
            }
        }
        return ans;
    }
private:
    long long getNext(long long n)
    {
        static map<long long,long long> next;
        long long num = n;
        long long ans;
        if(next.find(n)!=next.end())
        {
            return next[n];
        }
        bool all_nine = true;
        vector<int> nums;
        if(num ==0)
        {
            all_nine = false;
            nums.push_back(0);
        }
        else
        {
            while(num!=0)
            {
                nums.push_back(num%10);
                if(num%10!=9)
                {
                    all_nine = false;
                }
                num=num/10;
            }
        }
        if(all_nine)
        {
            ans = n+2;
        }
        else{
            if(nums.size()%2==1)
            {
                if(nums[nums.size()/2] !=9)
                {
                    ans = n + pow(10,nums.size()/2);
                }
                else
                {
                    int tmp = 0;
                    for(int i=0;i<nums.size()/2;i++)
                    {
                        tmp = tmp*10+nums[i];
                    }
                    tmp = tmp+1;
                    vector<int> tmp_v = toVector(tmp, 10);
                    reverse(tmp_v.begin(),tmp_v.end());
                    ans = toLongLong(tmp_v)
                           + tmp * pow(10, nums.size()/2+1);
                }                
            }
            else
            {
                int tmp = 0;
                for(int i=0;i<nums.size()/2;i++)
                {
                    tmp = tmp*10+nums[i];
                }
                tmp = tmp+1;
                // vector<int> tmp_v = toVector(tmp, 10);
                // reverse(tmp_v.begin(),tmp_v.end());
                ans=0;
                int ttmp=tmp;
                while(tmp!=0)
                {
                    ans=ans*10+tmp%10;
                    tmp=tmp/10;
                }
                ans = ans+ ttmp * pow(10, nums.size()/2);
            }
        }
        next.insert({n,ans});
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
