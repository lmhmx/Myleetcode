/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        int size = 0;
        while(p!=nullptr)
        {
            p=p->next;
            size++;
        }
        int front_num = size - n;
        ListNode* front = new ListNode(0,head);
        p = front;
        for (int i=0;i<front_num;i++)
        {
            p = p->next;
        }
        ListNode* t = p->next;
        // delete t;
        p->next = p->next->next;
        head = front->next;
        delete t;
        return head;
    }
};
// @lc code=end

