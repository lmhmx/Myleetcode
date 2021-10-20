/*
 * @lc app=leetcode.cn id=1897 lang=cpp
 *
 * [1897] 重新分配字符使所有字符串都相等
 */

// @lc code=start
# include <string>
# include <vector>
# include <list>
# include <iostream>
using namespace std;
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int* characters_num = new int[26];
        for (int i=0;i<26;i++){
            characters_num[i]=0;
        }
        for (string& word: words){
            for (auto& c:word){
                characters_num[c-'a']++;
            }
        }
        for (int i=0;i<26;i++){
            if(characters_num[i]%words.size()!=0){
                delete[] characters_num;
                return false;
            }
        }
        delete[] characters_num;
        return true;
    }
};
// @lc code=end

