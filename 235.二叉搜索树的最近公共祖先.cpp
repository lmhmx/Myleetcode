/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start

# include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        
        if(root==nullptr||p==nullptr||q==nullptr)
        {
            return nullptr;
        }
        TreeNode* tmp = p;
        if(p->val > q->val)
        {
            p=q;
            q=tmp;
        }
        while(cur!=nullptr)
        {
            if( p->val <= cur->val && cur->val <= q->val)
            {
                return cur;
            }
            if(q->val < cur->val)
            {
                cur = cur->left;
            }
            else if(p->val > cur->val)
            {
                cur = cur->right;
            }
            else
            {
                continue;
            }
        }
        return nullptr;
    }
};
// @lc code=end

