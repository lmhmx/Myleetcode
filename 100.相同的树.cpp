/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
# include <string>
# include <vector>
# include <list>
# include <iostream>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        list<TreeNode*> p_nodes;
        list<TreeNode*> q_nodes;
        bool result = true;
        if(p ==nullptr && q==nullptr){
            return true;
        }
        else if(p!=nullptr && q!=nullptr){
            if(p->val == q->val){
                p_nodes.push_back(p);
                q_nodes.push_back(q);
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
        while(1){
            if(p_nodes.size()==0){
                break;
            }
            // 左节点
            if(p_nodes.front()->left==nullptr && q_nodes.front()->left==nullptr){
                // do nothing
            }
            else if(p_nodes.front()->left!=nullptr && q_nodes.front()->left!=nullptr){
                if(p_nodes.front()->left->val != q_nodes.front()->left->val){
                    result = false;
                    break;
                }
                else{
                    p_nodes.push_back(p_nodes.front()->left);
                    q_nodes.push_back(q_nodes.front()->left);
                }
            }
            else{
                result = false;
                break;
            }
            // 右节点
            if(p_nodes.front()->right==nullptr && q_nodes.front()->right==nullptr){
                // do nothing
            }
            else if(p_nodes.front()->right!=nullptr && q_nodes.front()->right!=nullptr){
                if(p_nodes.front()->right->val != q_nodes.front()->right->val){
                    result = false;
                    break;
                }
                else{
                    p_nodes.push_back(p_nodes.front()->right);
                    q_nodes.push_back(q_nodes.front()->right);
                }
            }
            else{
                result = false;
                break;
            }

            p_nodes.pop_front();
            q_nodes.pop_front();
            
        }
        return result;
    }
};
// @lc code=end

