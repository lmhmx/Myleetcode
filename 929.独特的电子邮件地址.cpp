/*
 * @lc app=leetcode.cn id=929 lang=cpp
 *
 * [929] 独特的电子邮件地址
 */

// @lc code=start
#include <vector>

# include<string>
# include <unordered_set>

using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> email_set;
        string tmp;
        for (auto& email: emails){
            tmp = process(email);
            if(email_set.find(tmp) == email_set.end()){
                email_set.insert(tmp);
            }
        }
        return email_set.size();
    }
private:
    string process(string s){
        string result;
        int ata_pos;
        int has_plus=false;
        for(int i=0;i<s.size();i++){
            if(!has_plus){           
                if(s[i]!='@'){
                    if(s[i]!='.'){
                        if(s[i]=='+'){
                            has_plus=true;
                        }
                        else{
                            result.push_back(s[i]);
                        }
                    }
                    else{
                        // do nothing
                    }
                }
                else{
                    ata_pos=i;
                    break;
                }
            }
            else{
                if(s[i]!='@'){
                    // do nothing
                }
                else{
                    ata_pos=i;
                    break;
                }
            }
        }
        result.append(s.substr(ata_pos,s.size()-ata_pos));
        return result;
    }
};
// @lc code=end

