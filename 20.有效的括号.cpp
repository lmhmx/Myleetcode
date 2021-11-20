/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
# include <algorithm>
# include <string>
# include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i=0;i<s.size();i++)
        {
            if(s[i] == '(' || s[i] =='[' || s[i]=='{')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty())
                {
                    return false;
                }
                if(isMap(st.top(),s[i]))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if(!st.empty())
        {
            return false;
        }
        return true;
    }
private:
    bool isMap(char a, char b)
    {
        if(a=='(' && b ==')' || a=='[' && b==']' || a=='{' && b=='}')
        {
            return true;
        }
        return false;
    }
};
// int main()
// {
//     Solution s;
//     s.isValid("()");
//     return 0;
// }
// @lc code=end

