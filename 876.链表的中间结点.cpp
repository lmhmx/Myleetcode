/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
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
    ListNode* middleNode(ListNode* head) {
        int size = 0;
        ListNode* p = head;
        while(p!=nullptr)
        {
            size++;
            p=p->next;
        }
        int mid = size/2;
        p = head;
        for (int i=0;i<mid;i++)
        {
            p = p->next;
        }
        return p;
    }
};
// @lc code=end

