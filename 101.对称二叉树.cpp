/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
# include <vector>
# include <stack>
# include <queue>
# include <algorithm>
using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode* leftTree;
        TreeNode* rightTree;
        if(root==nullptr)
        {
            return true;
        }
        if(!isequal(root->left,root->right))
        {
            return false;
        }
        leftTree = root->left;
        rightTree = root->right;
        queue<TreeNode*> llayer[2];
        queue<TreeNode*> rlayer[2];
        TreeNode* pl;
        TreeNode* pr;
        if(leftTree==nullptr && rightTree == nullptr)
        {
            return true;
        }
        llayer[0].push(leftTree);
        rlayer[0].push(rightTree);
        int cur;
        int next;
        while(!llayer[0].empty()||!llayer[1].empty())
        {
            cur = llayer[0].empty()?1:0;
            next = 1-cur;
            while(!llayer[cur].empty())
            {
                pl = llayer[cur].front();
                pr = rlayer[cur].front();
                llayer[cur].pop();
                rlayer[cur].pop();
                if(isequal(pl->left, pr->right)&& isequal(pl->right,pr->left))
                {
                    if(pl->left!=nullptr)
                    {
                        llayer[next].push(pl->left);
                        rlayer[next].push(pr->right);
                    }
                    if(pl->right!=nullptr)
                    {
                        llayer[next].push(pl->right);
                        rlayer[next].push(pr->left);
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
private:
    bool isequal(TreeNode* a, TreeNode* b)
    {
        if(a==nullptr && b== nullptr)
        {
            return true;
        }
        else if(a!=nullptr && b!=nullptr)
        {
            if(a->val == b->val)
            {
                return true;
            }
        }
        return false;
    }
};
// int main()
// {
//     TreeNode** nodes = new TreeNode*[5];
//     nodes[4] = new TreeNode(3);
//     nodes[3] = new TreeNode(3);
//     nodes[2] = new TreeNode(2, nullptr, nodes[4]);
//     nodes[1] = new TreeNode(2, nullptr, nodes[3]);
//     nodes[0] = new TreeNode(1, nodes[1], nodes[2]);
//     Solution s;
//     s.isSymmetric(nodes[0]);
//     return 0;
// }
// @lc code=end

