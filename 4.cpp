# include <map>
# include <vector>
# include <set>
using namespace std;

// 这么做是哈密顿回路，确实是没有办法求解的（NP），需要转化成欧拉回路问题
class Solution {
public:
typedef pair<int, int> Node;
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        map<Node, set<Node>> graph;
        map<int, set<Node>> begin;
        map<int, set<Node>> end;
        for (auto& p:pairs)
        {
            Node n({p[0],p[1]});
            begin[p[0]].insert(n);
            end[p[1]].insert(n);
            if(begin.count(p[1]))
            {
                for (auto& b:begin[p[1]])
                {
                    graph[n].insert(b);
                }
            }
            
            if(end.count(p[0]))
            {
                for (auto& e:end[p[0]])
                {
                    graph[n].insert(e);
                }
            }
        }

    }
};