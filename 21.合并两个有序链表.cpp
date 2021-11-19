/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans = nullptr;
        ListNode* p = nullptr;
        ListNode* min_node = nullptr;
        while(l1!=nullptr && l2!=nullptr)
        {
            if(l1->val<l2->val)
            {
                min_node = l1;
            }
            else
            {
                min_node = l2;
            }
            
            if(ans == nullptr)
            {
                ans = min_node;
                p = min_node;
                min_node=min_node->next;
            }
            else
            {
                p->next = min_node;
                min_node=min_node->next;
                p=p->next;
            }
            if(l1->val<l2->val)
            {
                l1 = min_node;
            }
            else
            {
                l2 = min_node;
            }
        }
        if(l1==nullptr)
        {
            min_node = l2;
        }
        else
        {
            min_node = l1;
        }
        if(ans!=nullptr)
        {
            p->next = min_node;
        }
        else
        {
            if(l1!=nullptr)
            {
                ans = l1;
            }
            else
            {
                ans=l2;
            }
        }
        return ans;
    }
};
// @lc code=end

