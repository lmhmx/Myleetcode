/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        ListNode* header = new ListNode();
        
        header->next = head;
        ListNode* p_before = header;
        ListNode* p = head;
        ListNode* p_next = nullptr;
        
        while(p!=nullptr)
        {
            p_next = p->next;
            p->next = p_before;
            p_before = p;
            p = p_next;
        }
        if(header->next !=nullptr)
        {
            header->next->next = nullptr;
            head = p_before;
        }
        else
        {
            head = p;//p=nulllptr;
        }
        delete header;
        return head;
    }
};
// @lc code=end

