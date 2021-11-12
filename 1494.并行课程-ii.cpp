/*
 * @lc app=leetcode.cn id=1494 lang=cpp
 *
 * [1494] 并行课程 II
 */

// @lc code=start

// 第一次失败的原因是没有考虑到中间越级的依赖关系，
// 各个可以学的课程并不是完全等价的
// 接下来考虑从最高级向下
#include <vector>
# include <iostream>
using namespace std;

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<vector<bool>> graph(n,vector<bool>(n,false));
        
        vector<bool> learned(n,false);
        vector<bool> newlearned(n,false);
        vector<bool> notlearned(n, true);
        int x;
        int y;
        for (int i=0;i<relations.size();i++){
            x = relations[i][0] - 1;
            y = relations[i][1] - 1;
            graph[x][y] = true;
        }

        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cout << graph[i][j] <<" ";
            }
            cout <<endl;
        }

        int ans = 0;
        while(1){
            int newlearned_size = 0;
            for (int i = 0;i<n;i++){
                if(notlearned[i]){
                    if(newlearned_size<k){
                        if(checkCol(graph,i)){
                            newlearned[i] = true;
                            notlearned[i] = false;
                            newlearned_size++;
                        }
                        else{
                            //nothing
                        }
                    }
                    else{
                        break;
                    }
                }
                else{
                    //nothing
                }
            }
            if(newlearned_size == 0){
                break;
            }
            for (int i =0; i<n;i++){
                if(newlearned[i]){
                    for (int j=0;j<n;j++){
                        graph[i][j] = false;
                    }
                    newlearned[i] = false;
                    learned[i] = true;
                }
                else{
                    // nothing
                }
            }
            ans++;
        }
        return ans;
    }
private:
    // 检测一列是否全部为 0 ，全为0，返回true，否则返回false
    bool checkCol(vector<vector<bool>>& graph, int col){
        for (int i=0;i<graph.size();i++){
            if(graph[i][col]==1){
                return false;
            }
        }
        return true;
    }       
};
int main (){
    vector<vector<int>> a = {{12,8},{2,4},{3,7},{6,8},{11,8},{9,4},{9,7},{12,4},{11,4},{6,4},{1,4},{10,7},{10,4},{1,7},{1,8},{2,7},{8,4},{10,8},{12,7},{5,4},{3,4},{11,7},{7,4},{13,4},{9,8},{13,8}};
    Solution s;
    s.minNumberOfSemesters(13,a,9);
}
// @lc code=end

