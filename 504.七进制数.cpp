/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

// @lc code=start
# include<string>
# include <algorithm>
using namespace std;
class Solution {
public:
    string convertToBase7(int num) {
        string ans;
        if(num>=0)
        {
            ans=convertToBaseK(num, 7);
        }
        else
        {
            ans.push_back('-');
            ans.append(convertToBaseK(-num,7));
        }
        return ans;
    }
private:
    // 2<= k <= 10, num >= 0
    string convertToBaseK(int num, int k)
    {
        string ans;
        
        do
        {
            ans.push_back(num%k + '0');
            num = num/k;
        }while(num>0);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// @lc code=end

