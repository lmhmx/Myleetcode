/*
 * @lc app=leetcode.cn id=1620 lang=cpp
 *
 * [1620] 网络信号最好的坐标
 */

// @lc code=start
# include <string>
# include <vector>
# include <list>
# include <iostream>
# include <cmath>
using namespace std;
class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        // double ** grid=new double*[51];
        // for (int i=0;i<51;i++){
        //     grid[i] = new double[51];
        // }
        // for (int i=0;i<51;i++){
        //     for (int j=0;j<51;j++){
        //         grid[i][j]=0;
        //     }
        // }
        vector<int> result(2,0);
        int tmp_signal;
        int max_signal=0;
        double d;
        for (int i=0;i<51;i++){
            for (int j=0;j<51;j++){
                tmp_signal = 0;
                for (auto tower = towers.begin();tower!=towers.end();tower++){
                    //d=sqrt_result[power((*tower)[0]-i,(*tower)[1]-j)];
                    d=sqrt(power((*tower)[0]-i,(*tower)[1]-j));
                    if(d <= radius){
                        tmp_signal = tmp_signal+(*tower)[2]/(1+d);
                    }
                }
                if(tmp_signal>max_signal){
                    max_signal=tmp_signal;
                    result[0]=i;
                    result[1]=j;
                }
                //grid[i][j]=tmp_signal;
            }
        }
        // for (int i=0;i<51;i++){
        //     for (int j=0;j<51;j++){
        //         printf("%3.0lf",grid[i][j]);
        //     }
        //     printf("\n");
        // }

        // for (int i=0;i<51;i++){
        //     delete[] grid[i];
        // }

        // delete[] grid;

        return result;
    }
private:
    int power(int x, int y){
        return x*x+y*y;
    }
};
// int main(){
//     Solution s;
//     vector<vector<int>> v;
//     v.push_back({30,34,31});
//     v.push_back({10,44,24});
//     v.push_back({14,28,23});
//     v.push_back({50,38,1});
//     v.push_back({40,13,6});
//     v.push_back({16,27,9});
//     v.push_back({2,22,23});
//     v.push_back({1,6,41});
//     v.push_back({34,22,40});
//     v.push_back({40,10,11});
//     s.bestCoordinate(v,20);
// }
// @lc code=end

