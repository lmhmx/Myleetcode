/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* header = new ListNode();
        header->next = head;
        ListNode* p = head;
        ListNode* q = header;
        ListNode* deleteNode;
        while(p!=nullptr)
        {
            if(p->val == val)
            {
                deleteNode = p;
                q->next = p->next;
                p = q->next;
                delete deleteNode;
            }
            else
            {
                q = q->next;
                p = p->next;
            }
        }
        head = header->next;
        delete header;
        return head;
    }
};
// @lc code=end

