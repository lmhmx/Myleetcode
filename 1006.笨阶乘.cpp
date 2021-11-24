/*
 * @lc app=leetcode.cn id=1006 lang=cpp
 *
 * [1006] 笨阶乘
 */

// @lc code=start
class Solution {
public:
    int clumsy(int n) {
        int ans = 0;
        int a = 0;
        int b = 0;
        int c = 0;
        int d = 0;
        int first = 1;
        for (int i=n;i>=1;i--)
        {
            switch ((n-i)%4)
            {
            case 0:
                a = i;
                break;
            case 1:
                b = i;
                break;
            case 2:
                c = i;
                break;
            case 3:
                d = i;
                if(first==1)
                {
                    ans = ans +  a*b/c+d;
                    first = 0;
                }
                else
                {
                    ans = ans - a*b/c+d;
                }
                
                a=0;
                b=0;
                c=0;
                d=0;
                break;
            default:
                break;
            }
        }
        if(c!=0)
        {
            ans = ans + (2*first-1)* a*b/c+d;
        }
        else if(b!=0)
        {
            ans = ans + (2*first-1)*a*b;
        }
        else
        {
            ans = ans + (2*first-1)*a;
        }
        return ans;
    }
};
// int main()
// {
//     Solution s;
//     s.clumsy(3);
//     return 0;
// }
// @lc code=end

