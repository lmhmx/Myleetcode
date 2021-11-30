/*
 * @lc app=leetcode.cn id=473 lang=cpp
 *
 * [473] 火柴拼正方形
 */

// @lc code=start
# include <vector>
# include <map>
# include <unordered_map>
# include <iostream>
using namespace std;
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        
        int sum = 0;
        for (int i=0;i<matchsticks.size();i++)
        {
            sum = sum+matchsticks[i];
        }
        int length = sum/4;
        if(sum%4!=0)
        {
            return false;
        }
        map<pair<int,int>, bool> mp;
        bool ans = recurse(matchsticks, (1<<matchsticks.size())-1, 0,length,sum, mp);
        return ans;
    }
private:
    bool recurse(vector<int>& matchsticks, int not_use_mask, int done,int length, int sum, map<pair<int,int>, bool>& mp)
    { 
        
        // 如果已经利用这些没用过的元素尝试构成了还没做完的部分，直接返回结果
        if(mp.count({not_use_mask,done}))
        {
            return mp[{not_use_mask,done}];
        }
        // static int ii = 0;
        // cout <<ii++<<" ";
        // 如果已经做完的有3个了，那么，看最后一个是否可以做成（其实已经检查过了，再检查一遍也没有问题
        if(done == 3)
        {
            mp.insert({{not_use_mask,done},sum==length});
            return sum==length;
        }
        // 用还没有用到的火柴是否能够拼成剩下的个数
        bool ans = false;

        for (int i=0;i<matchsticks.size();i++)
        {
            if((not_use_mask&(1<<i))!=0)
            {
                if((sum-matchsticks[i])%length == 0)
                {
                    done++;
                }
                bool result=recurse(matchsticks, not_use_mask^(1<<i), done, length,sum-matchsticks[i], mp);
                if((sum-matchsticks[i])%length == 0)
                {
                    done--;
                }
                if(result)
                {
                    ans = true;
                    break;
                }
            }
        }
        mp.insert({{not_use_mask,done},ans});
        return ans;
    }
};
// int main()
// {
//     Solution s;
//     s.makesquare(vector<int>()={6035753,3826635,922363,6104805,1189018,6365253,364948,2725801,5577769,7857734,2860709,9554210,4883540,8712121,3545089});
//     return 0;
// }
// @lc code=end

