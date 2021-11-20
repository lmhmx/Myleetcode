/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
# include <string>
# include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        
        int flag = false;;
        auto a_i = a.rbegin(), b_i = b.rbegin();
        for (;a_i!=a.rend()&&b_i!=b.rend();a_i++,b_i++)
        {
            if(flag)
            {
                ans.push_back('0'+(*a_i == *b_i));
                flag = (*a_i == '1'||*b_i == '1');
            }
            else
            {
                ans.push_back('1' - (*a_i == *b_i));
                flag = (*a_i == '1'&&*b_i == '1');
            }
        }
        string::reverse_iterator it = (a_i ==a.rend()?b_i:a_i);
        string::reverse_iterator stop = (a_i ==a.rend()?b.rend():a.rend());
        for (;it!=stop;it++)
        {
            ans.push_back('0'+(flag != (*it-'0')));
            flag = flag&&(*it=='1');
        }
        if(flag)
        {
            ans.push_back('1');
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// int main()
// {
//     string a = "1";
//     string b = "111";
//     Solution s;
//     s.addBinary(a,b);
//     return 0;
// }
// @lc code=end

