/*
 * @lc app=leetcode.cn id=1286 lang=cpp
 *
 * [1286] 字母组合迭代器
 */

// @lc code=start
# define DEBUG

# include <string>
# include <vector>
# include <algorithm>
using namespace std;
class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        m_s = characters;
        m_n = combinationLength;
        m_choose.resize(m_s.size(),false);
        for (int i=0;i<m_n;i++)
        {
            m_choose[i] = true;
        }
        m_hasnext = true;
    }
    
    string next() {
        string ans;
        for (int i=0;i<m_choose.size();i++)
        {
            if(m_choose[i])
            {
                ans.push_back(m_s[i]);
            }
        }
        jumpTonext();
        return ans;
    }
    
    bool hasNext() {
        return m_hasnext;
    }
private:
    void jumpTonext()
    {
        // 从后往前数的第一个false,用于判定是否含有下一个
        int first_false = -1;
        for (int i = m_choose.size()-1;i>=0;i--)
        {
            if(m_choose[i] == true)
            {
                if(i!=m_choose.size()-1)
                {
                    if(m_choose[i+1] == false)
                    {
                        m_choose[i] = false;
                        m_choose[i+1] = true;
                        break;
                    }
                    else{
                        continue;
                    }
                }
                else
                {
                    continue;
                }
            }
            else{
                first_false = max(first_false, i);
            }
        }
        if(first_false == m_s.size() - m_n - 1)
        {
            m_hasnext = false;
        }
    }
private:
    string m_s;
    int m_n;
    bool m_hasnext;
    vector<bool> m_choose;
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

