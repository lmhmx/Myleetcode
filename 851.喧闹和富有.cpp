/*
 * @lc app=leetcode.cn id=851 lang=cpp
 *
 * [851] 喧闹和富有
 */

// @lc code=start
# include <string>
# include <vector>
# include <list>
# include <iostream>
using namespace std;
struct Node{
    int up_min;
    int quiet;
    int min_index;
    int index;
    vector<Node*> up_nodes;
};
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<Node*> nodes(quiet.size());
        for (int i=0;i<nodes.size();i++){
            nodes[i]=new Node();
        }
        for (int i=0;i<nodes.size();i++){
            nodes[i]->quiet = quiet[i];
            nodes[i]->up_min = nodes.size();
            nodes[i]->min_index = -1;
            nodes[i]->index = i;
        }
        for (int i=0;i<richer.size();i++){
            nodes[richer[i][1]]->up_nodes.push_back(nodes[richer[i][0]]);
        }
        for (int i=0;i<nodes.size();i++){
            updateNode(nodes[i]);
        }
        vector<int> answer(quiet.size());
        for (int i=0;i<quiet.size();i++){
            answer[i]=nodes[i]->min_index;
        }
        return answer;
    }
private:
    vector<int> updateNode(Node* node){
        if(node->up_min<node->quiet){
            // do nothing
        }
        else if(node->up_nodes.size()==0){
            node->up_min = node->quiet;
            node->min_index = node->index;
        }
        else{
            int tmp = node->quiet;
            int tmp_index = node->index;
            vector<int> tmp_result;
            for(int i = 0;i < node->up_nodes.size();i++){
                tmp_result = updateNode(node->up_nodes[i]);
                if(tmp_result[0]<tmp){
                    tmp=tmp_result[0];
                    tmp_index = tmp_result[1];
                }
            }
            node->up_min = tmp;
            node->min_index = tmp_index;
        }
        return {node->up_min,node->min_index};
    }

};
// int main(){
//     Solution s;
//     vector<vector<int>> richer;
//     richer.push_back({1,0});
//     richer.push_back({2,1});
//     richer.push_back({3,1});
//     richer.push_back({3,7});
//     richer.push_back({4,3});
//     richer.push_back({5,3});
//     richer.push_back({6,3});
//     vector<int> quiet={3,2,5,4,6,1,7,0};
//     s.loudAndRich(richer,quiet);

// }
// @lc code=end

