/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    TreeNode* invertTree(TreeNode* root) {
        if(root!=nullptr)
        {
            TreeNode* l = root->left;
            TreeNode* r = root->right;
            invertTree(root->left);
            invertTree(root->right);
            root->left = r;
            root->right = l;
        }
        return root;
    }
};
// @lc code=end

