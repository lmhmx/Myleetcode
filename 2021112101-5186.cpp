# include <vector>
# include <map>
# include <algorithm>
using namespace std;
struct NodeVal{
    vector<int> arr;
    int low;
    int high;
};
typedef NodeVal T;
struct binNode{
    binNode(binNode* parent = nullptr,binNode* left = nullptr,binNode* right = nullptr)
    {
        this->left = left;
        this->right = right;
        this->parent = parent;
    }
    binNode(T& val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    }
    
    void setVal(T& val)
    {
        this->val = val;
    }
    T val;
    binNode* left;
    binNode* right;
    binNode* parent;
};
class binTree{
public:
    binTree()
    {
        root = nullptr;
    };
    binTree(binNode* root)
    {
        this->root = root;
    }
    void setRoot(binNode* node)
    {
        root = node;
    }
    binNode* getRoot()
    {
        return root;
    }
    void insertLeft(binNode* parent, binNode* child)
    {
        parent->left = child;
        child->parent = parent;
    }
    void insertRight(binNode* parent, binNode* child)
    {
        parent->right = child;
        child->parent = parent;
    }
    void clear()
    {
        clear(root);
    }
    
    ~binTree()
    {
        clear();
    }
private:
    void clear(binNode* node)
    {
        if(node != nullptr)
        {
            if(node->left!=nullptr)
            {
                clear(node->left);
            }
            if(node->right!=nullptr)
            {
                clear(node->right);
            }
            delete node;
        }
        
    }
private:
    binNode* root;
    
};
class RangeFreqQuery {
public:
    RangeFreqQuery(vector<int>& arr) {
        binNode* root = new binNode();
        tree.setRoot(root);
        addToRanges(arr, 0, arr.size(), root);
    }
    
    int query(int left, int right, int value) {
        return querylayer(left, right, value, tree.getRoot());
    }
    
private:
    int querylayer(int left, int right, int value, binNode* node)
    {
        int ans = 0;
        // node 的 大小如果是1，那么必符合两端都符合，如果不同，说明node的范围过大，node必有两个孩子
        if(left==node->val.low&&right == node->val.high-1)
        {
            ans = queryNum(node->val.arr, value);
        }
        else if(left > node->left->val.high - 1)
        {
            ans = querylayer(left, right, value, node->right);
        }
        else if(right < node->left->val.high)
        {
            ans = querylayer(left, right, value, node->left);
        }
        else
        {
            ans = querylayer(left, node->left->val.high-1, value, node->left);
            ans = ans + querylayer(node->right->val.low, right, value, node->right);
        }
        return ans;
    }
    int queryNum(vector<int>& arr, int v)
    {
        int ans = queryNum(arr, v, 0, arr.size());
        return ans;
    }
    int queryNum(vector<int>& arr, int v, int low, int high)
    {
        if(arr[low] == v && arr[high-1] == v)
        {
            return high - low;
        }
        else if(arr[low]>v)
        {
            return 0;
        }
        else if(arr[high-1]<v)
        {
            return 0;
        }
        else
        {
            int a = queryNum(arr, v, low, (high+low)/2);
            int b = queryNum(arr, v, (low+high)/2, high);
            return a+b;
        }
        return 0;
    }
    void addToRanges(vector<int>& arr, int low, int high, binNode* root)
    {
        vector<int> a(arr.begin()+low, arr.begin()+high);
        sort(a.begin(),a.end());
        NodeVal val;
        val.low = low;
        val.high = high;
        val.arr = a;

        root->setVal(val);
        if(high-low==1)
        {
            return;
        }
        binNode* left = new binNode();
        binNode* right = new binNode();
        tree.insertLeft(root, left);
        tree.insertRight(root, right);
        addToRanges(arr, low, (high+low)/2,left);
        addToRanges(arr, (high+low)/2, high, right);
    }
private:
    binTree tree;
};

int main()
{
    vector<int> b = {2,2,1,2,2};
    RangeFreqQuery a(b);
    a.query(2,4,1);
    a.query(1,3,1);
    a.query(0,2,1);
    return 0;

}
/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */