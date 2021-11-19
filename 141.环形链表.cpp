/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
# include <vector>
# include <set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> s;
        ListNode* p = head;
        while(p!=NULL)
        {
            if(s.find(p)==s.end())
            {
                s.insert(p);
            }
            else
            {
                return true;
            }
            p=p->next;
        }
        return false;
    }
};
// @lc code=end

