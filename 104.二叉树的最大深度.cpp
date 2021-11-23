/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> layer[2];
        if(root!=nullptr)
        {
            layer[0].push(root);
        }
        int cur;
        int next;
        TreeNode* p;
        while(!layer[0].empty()||!layer[1].empty())
        {
            cur = layer[0].empty()?1:0;
            next = 1-cur;
            while(!layer[cur].empty())
            {
                p = layer[cur].front();
                layer[cur].pop();
                if(p->left!=nullptr)
                {
                    layer[next].push(p->left);
                }
                if(p->right!=nullptr)
                {
                    layer[next].push(p->right);
                }
            }
            ans++;
        }
        return ans;
    }
};
// @lc code=end

