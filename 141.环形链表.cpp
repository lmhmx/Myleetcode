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

        ListNode* p = nullptr;
        if(head != nullptr)
        {   
            p = head->next;
        }
        ListNode* q = head;
        while(p!=nullptr && q!=nullptr)
        {
            if(p==q)
            {
                return true;
            }
            else
            {
                p=p->next;
                if(p==nullptr)
                {
                    return false;
                }
                else
                {
                    p=p->next;
                }
                q=q->next;
            }
        }
        return false;
    }
};
// @lc code=end

