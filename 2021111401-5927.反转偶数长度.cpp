# include <iostream>
# include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        
        ListNode* p = head;
        vector<int> a;
        while(p!=nullptr)
        {
            a.push_back(p->val);
            p=p->next;
        }
        int group = 1;
        int low=0;
        int high=0;
        while(1)
        {
            low = low+group-1;
            high = min(low+group, (int)a.size());
            if((high-low)%2==0)
            {
                reverse(a, low, high);
            }
            if(high==a.size())
            {
                break;
            }
            group++;
        }
        int index = 0;
        p = head;
        while(p!=nullptr)
        {
            p->val = a[index];
            index++;
            p=p->next;
        }
        return head;
    }
private:
    void reverse(vector<int>& v, int low, int high)
    {
        for (int i=low;i<(high+low)/2;i++)
        {
            int tmp = v[i];
            v[i] = v[high-1-(i-low)];
            v[high-1-(i-low)] = tmp;
        }
    }
};
int main()
{

}