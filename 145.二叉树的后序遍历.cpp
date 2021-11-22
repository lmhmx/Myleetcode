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
        list<TreeNode*> nodes;
        TreeNode* p;
        stack<bool> left_visited;
        stack<bool> right_visited;
        if(root!=nullptr)
        {
            nodes.push_back(root);
            left_visited.push(false);
            right_visited.push(false);
        }
        while(!nodes.empty())
        {
            p = nodes.front();
            if(p->right!=nullptr && !right_visited.top())
            {
                nodes.push_front(p->right);
                right_visited.pop();
                right_visited.push(true);
                if(p->left!=nullptr && !left_visited.top())
                {
                    nodes.push_front(p->left);
                    left_visited.pop();
                    left_visited.push(true);
                    left_visited.push(false);
                    right_visited.push(false);
                }
                left_visited.push(false);
                right_visited.push(false);
                
            }
            else if(p->left!=nullptr && !left_visited.top())
            {
                nodes.push_front(p->left);
                left_visited.pop();
                left_visited.push(true);
                left_visited.push(false);
                right_visited.push(false);
            }
            else
            {
                ans.push_back(p->val);
                nodes.pop_front();
                left_visited.pop();
                right_visited.pop();
            }  
        }
        return ans;
    }
};
int main()
{
    Solution s;
    TreeNode* a= new TreeNode(1);
    TreeNode* b= new TreeNode(2);
    TreeNode* c= new TreeNode(3);
    c->left = a;
    c->right = b;
    s.postorderTraversal(c);
    return 0;
}
// @lc code=end

