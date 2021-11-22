/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        list<TreeNode*> nodes;
        TreeNode* p;
        stack<bool> left_visited;
        if(root!=nullptr)
        {
            nodes.push_front(root);
            left_visited.push(false);
        }
        
        while(!nodes.empty())
        {
            p = nodes.front();
            if(p->left!=nullptr && !left_visited.top())
            {
                nodes.push_front(p->left);
                left_visited.pop();
                left_visited.push(true);
                left_visited.push(false);
            }
            else
            {
                ans.push_back(p->val);
                left_visited.pop();
                nodes.pop_front();
                if(p->right!=nullptr)
                {
                    nodes.push_front(p->right);
                    left_visited.push(false);
                }

            }
        }
        return ans;
    }
};
// @lc code=end

