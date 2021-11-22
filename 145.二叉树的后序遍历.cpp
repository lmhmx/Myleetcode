/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start

# include<vector>
# include <stack>
# include <list>
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorderTraversal(root, ans);
        return ans;
    }
private:
    void postorderTraversal(TreeNode* node, vector<int>& ans)
    {
        if(node==nullptr)
        {
            return;
        }
        postorderTraversal(node->left, ans);
        postorderTraversal(node->right, ans);
        ans.push_back(node->val);
    }
};
// @lc code=end

