/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */
// @lc code=start
# include <vector>
# include <stack>
# include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        queue<TreeNode*>  layer[2];
        if(root!=nullptr)
        {
            layer[0].push(root);
        }
        int cur_layer;
        int next_layer;
        TreeNode* p;
        while(!layer[0].empty() || !layer[1].empty())
        {
            if(!layer[0].empty())
            {
                cur_layer = 0;
                next_layer = 1;
            }
            else
            {
                cur_layer = 1;
                next_layer = 0;
            }
            ans.push_back(vector<int>());
            while(!layer[cur_layer].empty())
            {
                p = layer[cur_layer].front();
                layer[cur_layer].pop();
                ans.back().push_back(p->val);
                if(p->left!=nullptr)
                {
                    layer[next_layer].push(p->left);
                }
                if(p->right!=nullptr)
                {
                    layer[next_layer].push(p->right);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

