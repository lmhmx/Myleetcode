# include <vector>
using namespace std;
class Solution {
public:
    long long kMirror(int k, int n) {
        long long n1 = 1;
        long long n2 = 1;
        long long ans = 0;
        long long size = 0;
        long long num1 = 0;
        long long num2 = 0;
        while(size < n)
        {
            num1=getKn(k, n1);
            num2=getKn(k, n2);
            if(num1==num2)
            {
                ans+=num1;
                size++;
            }
            else if(num1<num2)
            {
                n1++;
            }
            else
            {
                n2++;
            }
        }
        return ans;
    }
private:
    long long getKn(int k, long long n)
    {
        if(n<=k-1)
        {
            return k-1;
        }
        n=n-(k-1);
        if(n<=(k-1))
        {
            return k*n + n;
        }
        n=n-(k-1);
        if(n<=)
    }
};