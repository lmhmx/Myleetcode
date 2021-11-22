/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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

# include <vector>
# include <list>
using namespace std;
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        list<TreeNode*> nodes;
        TreeNode* p = root;
        if(root!=nullptr)
        {
            nodes.push_back(root);
        }
        while(!nodes.empty())
        {
            p = nodes.front();
            nodes.pop_front();
            if(p->right!=nullptr)
            {
                nodes.push_front(p->right);
            }
            if(p->left!=nullptr)
            {
                nodes.push_front(p->left);
            }
            ans.push_back(p->val);
            
            
        }
        return ans;
    }
};
// @lc code=end

