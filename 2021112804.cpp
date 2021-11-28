# include <algorithm>
# include <vector>
# include <map>
# include <set>
using namespace std;
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int, set<vector<int>>> time_meeting;
        set<int> ans;
        for (int i=0;i<meetings.size();i++)
        {
            time_meeting[meetings[i][2]].insert(vector<int>()={meetings[i][0],meetings[i][1]});
        }
        ans.insert(0);
        ans.insert(firstPerson);
        for (auto& time_i:time_meeting)
        {
            traverse(time_i.second, ans);
        }
        return vector<int>(ans.begin(),ans.end());
    }
private:
    void traverse(set<vector<int>>& meetings, set<int>& known)
    {
        map<int,set<int>> matrix;
        for (auto& i:meetings)
        {
            matrix[i[0]].insert(i[1]);
            matrix[i[1]].insert(i[0]);
        }
        for (auto& i:matrix)
        {
            if(known.count(i.first))
            {
                dfs(i.first, matrix, known);
            }
            
        }
        
    }
    void dfs(int x, map<int,set<int>>& matrix, set<int>& known)
    {
        for (auto& y:matrix[x])
        {
            if(!known.count(y))
            {
                known.insert(y);
                dfs(y,matrix,known);
            }
        }
    }
};