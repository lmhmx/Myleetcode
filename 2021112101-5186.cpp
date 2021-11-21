# include <vector>
# include <map>
# include <algorithm>
using namespace std;
typedef vector<int> T;
struct binNode{
    binNode()
    {
        left = nullptr;
        right = nullptr;
        parent = nullptr;
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

    };
    void insertLeft(binNode* parent, binNode* child)
    {
        parent->left = child;
    }

private:
    binNode* root;
    
};
class RangeFreqQuery {
public:
    RangeFreqQuery(vector<int>& arr) {
        addToRanges(arr, 0, arr.size(), 0);
    }
    
    int query(int left, int right, int value) {
        return querylayer(left, right, 0, value, true);
    }
    
private:
    int querylayer(int left, int right, int layer, int value, bool isFirst)
    {
        if(1)
        {

        }
    }
    int queryNum(vector<int>& arr, int v)
    {
        return 0;
    }
    void addToRanges(vector<int>& arr, int low, int high, int layer)
    {
        if(ranges.find(layer)==ranges.end())
        {
            ranges.insert({layer, vector<layerBlock>()});
        }

        vector<int> a(arr.begin()+low, arr.begin()+high);
        sort(a.begin(),a.end());
        ranges[layer].push_back({a,low,high});
        if(high-low==1)
        {
            return;
        }
        addToRanges(arr, low, (high+low)/2,layer+1);
        addToRanges(arr, (high+low)/2, high, layer+1);
    }
private:
     ranges;
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */