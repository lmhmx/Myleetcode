/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        int MINUS_INFTY = -200;
        ListNode* header = new ListNode(MINUS_INFTY, head);
        ListNode* p = header;
        ListNode* p_next = p->next;
        while(p_next!=nullptr)
        {
            if(p->val == p_next->val)
            {
                p->next = p_next->next;
                delete p_next;
                p_next = p->next;
            }
            else
            {
                p = p_next;
                p_next = p->next;
            }
        }
        head = header->next;
        delete header;
        return head;
    }
};
// @lc code=end

