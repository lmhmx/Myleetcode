/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */

// @lc code=start
# include <vector>
# include <stack>
# include <queue>
# include <algorithm>
using namespace std;
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr)
        {
            return false;
        }
        if(root->left == nullptr && root->right==nullptr)
        {
            return root->val == targetSum;
        }
        else if(root->left !=nullptr && root->right!=nullptr)
        {
            return hasPathSum(root->left,targetSum-root->val)
                    ||hasPathSum(root->right, targetSum-root->val);
        }
        else if(root->left == nullptr && root->right!=nullptr)
        {
            return hasPathSum(root->right, targetSum-root->val);
        }
        else if(root->left!=nullptr && root->right == nullptr)
        {
            return hasPathSum(root->left, targetSum-root->val);
        }
        return false;
        
    }
};
// @lc code=end

