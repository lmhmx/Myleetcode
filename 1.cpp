# include <vector>
# include <set>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> num;
        int tmp;
        for (int i=0;i<digits.size();i++)
        {
            for (int j=0;j<digits.size();j++)
            {
                for (int k=0;k<digits.size();k++)
                {
                    if(i!=j &&i!=k && j!=k)
                    {
                        tmp = digits[i]*100+digits[j]*10+digits[k];
                        if(tmp>99 && tmp%2==0)
                        {
                            num.insert(tmp);
                        }
                    } 
                }
            }
        }
        vector<int> ans(num.begin(),num.end());
        return ans;
    }
};