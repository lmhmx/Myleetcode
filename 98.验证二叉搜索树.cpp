/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
# include <stack>
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
    bool isValidBST(TreeNode* root) {
        if(root==nullptr)
        {
            return true;
        }
        stack<int> min_s;
        stack<int> max_s;
        max_s.push(root->val);
        bool l = isValidBST(root->left, min_s, max_s);
        max_s.pop();
        min_s.push(root->val);
        bool r = isValidBST(root->right, min_s, max_s);
        return l&&r;
    }
private:
    bool isValidBST(TreeNode* cur, stack<int>& min_s, stack<int>& max_s)
    {
        if(cur == nullptr)
        {
            return true;
        }
        else
        {
            if(!min_s.empty())
            {
                if(cur->val <= min_s.top())
                {
                    return false;
                }
                else
                {
                    // nothing
                }
            }
            if(!max_s.empty())
            {
                if(cur->val>=max_s.top())
                {
                    return false;
                }
            }
            
            min_s.push(cur->val);
            bool r = isValidBST(cur->right,min_s, max_s);
            min_s.pop();
            
            max_s.push(cur->val);
            bool l = isValidBST(cur->left, min_s, max_s);
            max_s.pop();
            return l&&r;
        }
        return true;
    }
};
// int main()
// {
//     Solution s;
//     s.isValidBST(0);
//     return 0;
// }
// @lc code=end

