# include <string>
using namespace  std;

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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startstr;
        findValue(root, startValue, startstr);
        string deststr;
        findValue(root, destValue, deststr);
        int common = 0;
        for (int i=0;i<startstr.size(),i<deststr.size();i++)
        {
            if(startstr[i]==deststr[i])
            {
                common++;
            }
            else
            {
                break;
            }
        }
        startstr = startstr.substr(common);
        deststr = deststr.substr(common);
        string ans;
        for (int i=startstr.size()-1;i>=0;i--)
        {
            ans.push_back('U');
        }
        ans.append(deststr);
        return ans;
    }
private:
    bool findValue(TreeNode* root, int value, string& str)
    {
        if(root!=nullptr)
        {
            if(root->val==value)
            {
                return true;
            }
            else
            {
                if(root->left!=nullptr)
                {
                    if(root->left->val == value)
                    {
                        str.push_back('L');
                        return true;
                    }
                    else
                    {
                        str.push_back('L');
                        if(findValue(root->left, value, str))
                        {
                            return true;
                        }
                        str.pop_back();
                    }
                }
                if(root->right!=nullptr)
                {
                    if(root->right->val == value)
                    {
                        str.push_back('R');
                        return true;
                    }
                    else
                    {
                        str.push_back('R');
                        if(findValue(root->right, value, str))
                        {
                            return true;
                        }
                        str.pop_back();
                    }
                }
            }
        }
        return false;
    }
};
int main()
{
    Solution s;
    TreeNode** n=new TreeNode*[7];
    for (int i=0;i<7;i++)
    {
        n[i] = new TreeNode(i);
    }
    n[5]->left=n[1];
    n[5]->right = n[2];
    n[1]->left = n[3];
    n[2]->left = n[6];
    n[2]->right = n[4];
    s.getDirections(n[5], 3,6);
    return 0;
}