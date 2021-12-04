/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr && root2 == nullptr)
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode();
        mergeTrees(root, root1, root2);
        return root;
    }
private:
    void mergeTrees(TreeNode* root, TreeNode* root1, TreeNode* root2)
    {
        if(root1!=nullptr)
        {
            if(root2!=nullptr)
            {
                root->val = root1->val+root2->val;
                if(!(root1->left==nullptr && root2->left ==nullptr))
                {
                    TreeNode* left = new TreeNode();
                    root->left = left;
                    mergeTrees(left, root1->left, root2->left);
                }
                
                if(!(root1->right==nullptr && root2->right ==nullptr))
                {
                    TreeNode* right = new TreeNode();
                    root->right = right;
                    mergeTrees(right, root1->right, root2->right);
                }
            }
            else
            {
                copyTree(root, root1);
            }
        }
        else
        {
            copyTree(root, root2);
        }
    }

    // 将非空的oldroot复制到非空的root中
    void copyTree(TreeNode* root, TreeNode* oldroot)
    {
        root->val = oldroot->val;
        if(oldroot->left!=nullptr)
        {
            TreeNode* left = new TreeNode();
            root->left = left;
            copyTree(root->left, oldroot->left);
        }
        
        if(oldroot->right!=nullptr)
        {
            TreeNode* right = new TreeNode();
            root->right = right;
            copyTree(root->right, oldroot->right);
        }
    }
};
// @lc code=end

