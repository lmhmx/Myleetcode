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
        // 最后一个
        bool last = m_choose.back();
        // 如果最后一个是0，那么往前找第1个1
        // 如果是1，往前找第1个0和0前面的第1个1
        if(last==false)
        {
            for (int i = m_choose.size()-1;i>=0;i--)
            {
                if(m_choose[i] == true)
                {
                    m_choose[i] = false;
                    m_choose[i+1] = true;
                    return;
                }
            }
        }
        else  //最后一个是1
        {
            int num_1 = 1;
            int find_0 = false;
            for (int i = m_choose.size()-1;i>=0;i--)
            {
                if(m_choose[i] == false)
                {
                    find_0 = true;
                }
                else
                {
                    if(!find_0)
                    {
                        num_1++;
                    }
                    else
                    {
                        m_choose[i] = false;
                        for (int k=i+1;k<m_choose.size();k++)
                        {
                            if(k-i<=num_1)
                            {
                                m_choose[k]=true;
                            }
                            else
                            {
                                m_choose[k] = false;
                            }
                        }
                        return;
                    }
                    
                }
            }
        }
        m_hasnext = false;
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

