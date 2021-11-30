/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
# include <string>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int low = 0;
        for (int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                reverse(s, low, i);
                low = i+1;
            }
        }
        reverse(s, low, s.size());
        return s;
    }
private:
    void reverse(string& s, int low, int high)
    {
        int mid=(low+high)/2;
        char tmp;
        for (int i=low;i<mid;i++)
        {
            tmp = s[i];
            s[i] = s[high-1-(i-low)];
            s[high-1-(i-low)] = tmp;
        }
    }
};
// @lc code=end

