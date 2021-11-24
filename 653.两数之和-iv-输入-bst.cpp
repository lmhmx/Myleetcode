/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
 */

// @lc code=start
# include <vector>
# include <unordered_set>
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
    bool findTarget(TreeNode* root, int k) {
        vector<int> nodes_num;
        traverse(root, nodes_num);
        unordered_set<int> before;
        
        for (int i=0;i<nodes_num.size();i++)
        {
            if(before.find(k- nodes_num[i])!=before.end())
            {
                return true;
            }
            before.insert(nodes_num[i]);
        }
        return false;
    }
private:
    void traverse(TreeNode* root, vector<int>& nodes_num)
    {
        if(root!=nullptr)
        {
            nodes_num.push_back(root->val);
            traverse(root->left,nodes_num);
            traverse(root->right, nodes_num);
        }
    }
};
// @lc code=end

