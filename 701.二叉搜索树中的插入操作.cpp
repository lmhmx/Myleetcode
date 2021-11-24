/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
 */

// @lc code=start

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr)
        {
            root = new TreeNode(val);
            return root;
        }
        if(root->val<val)
        {
            insertIntoBST(root, root->right, val);
        }
        else
        {
            insertIntoBST(root, root->left, val);
        }
        
        return root;
    }
private:
    TreeNode* insertIntoBST(TreeNode* parent, TreeNode* current, int val)
    {
        if(current==nullptr)
        {
            current = new TreeNode(val);
            if(parent->val<val)
            {
                parent->right = current;
            }
            else
            {
                parent->left = current;
            }
        }
        else
        {
            if(current->val<val)
            {
                return insertIntoBST(current, current->right, val);
            }
            else
            {
                return insertIntoBST(current, current->left, val);
            }
        }
        return nullptr;
    }
};
// @lc code=end

