// /*
//  * @lc app=leetcode.cn id=1494 lang=cpp
//  *
//  * [1494] 并行课程 II
//  */

// // @lc code=start

// // 第一次失败的原因是没有考虑到中间越级的依赖关系，
// // 各个可以学的课程并不是完全等价的
// // 接下来考虑从最高级向下
// #include <vector>
// # include <iostream>
// using namespace std;

// class Solution {
// public:
//     int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
//         vector<vector<bool>> graph(n,vector<bool>(n,false));
        
//         vector<bool> learned(n,false);
//         vector<bool> newlearned(n,false);
//         vector<bool> notlearned(n, true);
//         int x;
//         int y;
//         for (int i=0;i<relations.size();i++){
//             x = relations[i][0] - 1;
//             y = relations[i][1] - 1;
//             graph[x][y] = true;
//         }

//         for (int i=0;i<n;i++){
//             for (int j=0;j<n;j++){
//                 cout << graph[i][j] <<" ";
//             }
//             cout <<endl;
//         }

//         int ans = 0;
//         while(1){
//             int newlearned_size = 0;
//             for (int i = 0;i<n;i++){
//                 if(notlearned[i]){
//                     if(newlearned_size<k){
//                         if(checkCol(graph,i)){
//                             newlearned[i] = true;
//                             notlearned[i] = false;
//                             newlearned_size++;
//                         }
//                         else{
//                             //nothing
//                         }
//                     }
//                     else{
//                         break;
//                     }
//                 }
//                 else{
//                     //nothing
//                 }
//             }
//             if(newlearned_size == 0){
//                 break;
//             }
//             for (int i =0; i<n;i++){
//                 if(newlearned[i]){
//                     for (int j=0;j<n;j++){
//                         graph[i][j] = false;
//                     }
//                     newlearned[i] = false;
//                     learned[i] = true;
//                 }
//                 else{
//                     // nothing
//                 }
//             }
//             ans++;
//         }
//         return ans;
//     }
// private:
//     // 检测一列是否全部为 0 ，全为0，返回true，否则返回false
//     bool checkCol(vector<vector<bool>>& graph, int col){
//         for (int i=0;i<graph.size();i++){
//             if(graph[i][col]==1){
//                 return false;
//             }
//         }
//         return true;
//     }       
// };
// int main (){
//     vector<vector<int>> a = {{12,8},{2,4},{3,7},{6,8},{11,8},{9,4},{9,7},{12,4},{11,4},{6,4},{1,4},{10,7},{10,4},{1,7},{1,8},{2,7},{8,4},{10,8},{12,7},{5,4},{3,4},{11,7},{7,4},{13,4},{9,8},{13,8}};
//     Solution s;
//     s.minNumberOfSemesters(13,a,9);
// }

# include <iostream>
# include <vector>
using namespace std;
class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> prerequisite(n, 0);
        for (const auto& pair : relations) {
            int pre = pair[0] - 1;
            int after = pair[1] - 1;
            // 举例：prerequisite[1] = 0110 表示1的先修课为2和3
            prerequisite[after] |= 1<<pre;
        }

        int totalState = 1 << n;
        vector<int> dp(totalState, 16);
        // 0为不需要上任何课的状态，因此不需要学期
        dp[0] = 0;

        vector<int> cnt(totalState);
        cnt[0] = 0;
        // 小技巧，计算每个数字的二进制数中，1的个数
        for (int i = 1; i < totalState; ++i) {
            cnt[i] = cnt[i>>1] + (i&1);
        }

        // taken表示已经上过的课，假设taken = 0111，表示课程1 2 3已经上过了
        for (int taken = 0; taken < totalState; ++taken) {
            if (dp[taken] > n) continue;
            int cur = 0;
            // 在上过taken的基础上，还有哪些课可以上，要满足两个条件
            // 1. ((taken & (1 << j)) == 0) 表示这个课在taken中没上过
            // 2. ((prerequisite[j] & taken) == prerequisite[j]) 表示这个课的先修课已经上完了
            for (int j = 0; j < n; ++j) {
                if (((taken & (1 << j)) == 0) && ((prerequisite[j] & taken) == prerequisite[j])) {
                    // 存这学期可以上的课，注意，可以上不代表一定要上，也不一定要上满，这题的本质是NPC问题，任何贪心的思想都是错的，这个操作用下面枚举子集的方法实现
                    cur |= (1 << j);
                }
            }
            // 枚举cur的子集，比如cur = 111，它的子mask集合就是{111, 110, 101 011, 100, 010, 001}
            for (int subMask = cur; subMask != 0; subMask = subMask-1 & cur) {
                if (cnt[subMask] <= k) {
                    // 动态规划的思想，之前上完taken，这学期再上subMask，看看会不会更好
                    dp[taken|subMask] = min(dp[taken|subMask], dp[taken] + 1);
                }
            }
        }
        
        return dp[totalState - 1];
    }
};


// @lc code=end

