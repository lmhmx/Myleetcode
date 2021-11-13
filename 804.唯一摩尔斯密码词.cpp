/*
 * @lc app=leetcode.cn id=804 lang=cpp
 *
 * [804] 唯一摩尔斯密码词
 */

// @lc code=start
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse;
        for (int i=0;i<words.size();i++)
        {
            morse.push_back(toMorse(words[i]));
        }
        sort(morse.begin(),morse.end());
        int ans=1;
        for(int i=1;i<morse.size();i++)
        {
            if(morse[i]!=morse[i-1])
            {
                ans++;
            }
        }
        return ans;
    }
private:
    string toMorse(string& s)
    {
        static vector<string> MORSE_CODE(
        {
            ".-","-...","-.-.","-..",".",
            "..-.","--.","....","..",".---",
            "-.-",".-..","--","-.","---",".--.",
            "--.-",".-.","...","-","..-","...-",
            ".--","-..-","-.--","--.."
        }
        );
        string morse;
        for (int i=0;i<s.size();i++)
        {
            morse.append(MORSE_CODE[s[i]-'a']);
        }
        return morse;
    }

};
// @lc code=end

