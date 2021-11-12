/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
        // 不可能出现的数字
        int NO_NUM = -11111111;
        ListNode* frontNode = new ListNode(NO_NUM,head);
        ListNode* beforeNode = frontNode;
        ListNode* nextNode = frontNode->next;
        ListNode* nextnextNode;
        while(beforeNode->next!=nullptr){
            nextNode=beforeNode->next;
            if(nextNode->next!=nullptr){
                nextnextNode = nextNode->next;
                if(nextNode->val == nextnextNode->val)
                {
                    while(nextnextNode!=nullptr)
                    {
                        if(nextnextNode->val == nextNode->val)
                        {
                            nextnextNode=nextnextNode->next;
                        }
                        else
                        {
                            break;
                        }
                    }
                    beforeNode->next = nextnextNode;
                }
                else{
                    beforeNode= beforeNode->next;
                }
            }
            else{
                beforeNode= beforeNode->next;
            }
            
        }
        head = frontNode->next;
        delete frontNode;
        return head;
    }
};
// @lc code=end

