# include <vector>
using namespace std;
class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int step = 0;
        int left = capacity;
        for (int i=0;i<plants.size();i++)
        {
            if(left>=plants[i])
            {
                left = left-plants[i];
                step++;
            }
            else
            {
                left = capacity-plants[i];
                step = step+i*2+1;
            }
        }
        return step;
    }
};