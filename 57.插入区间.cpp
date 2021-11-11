/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
# include <iostream>
# include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        
        
        vector<int> insertInterval;
        int left = -1;
        int right = -1;
        for (int i=0;i<intervals.size();i++){
            if(newInterval.size()==0){
                result.push_back(intervals[i]);
            }
            else if(newInterval.size()==1){
                if(intervals[i][0]> newInterval[0]){
                    result.push_back(vector<int>()={left,newInterval[0]});
                    newInterval.clear();
                    result.push_back(intervals[i]);
                }
                else{
                    if(intervals[i][1]>=newInterval[0]){
                        result.push_back(vector<int>()={left,intervals[i][1]});
                        newInterval.clear();
                    }
                }
            }
            else if(newInterval.size()==2){
                if(intervals[i][0] <= newInterval[0] && newInterval[0]<=intervals[i][1]){
                    left = intervals[i][0];
                    if( newInterval[1] > intervals[i][1]){
                        newInterval.erase(newInterval.begin());
                    }
                    else{
                        result.push_back(intervals[i]);
                        newInterval.clear();
                    }
                }
                else if(intervals[i][0]>newInterval[0]){
                    if(newInterval[1] < intervals[i][0]){
                        result.push_back(newInterval);
                        result.push_back(intervals[i]);
                        newInterval.clear();
                    }
                    else if(newInterval[1]<=intervals[i][1]){
                        result.push_back(vector<int>()={newInterval[0],intervals[i][1]});
                        newInterval.clear();
                    }
                    else{
                        left = newInterval[0];
                        newInterval.erase(newInterval.begin());
                    }
                }
                else{
                    result.push_back(intervals[i]);
                }
            }
        }
        if(newInterval.size()==2){
            result.push_back(newInterval);
        }
        else if(newInterval.size()==1){
            result.push_back(vector<int>()={left,newInterval[0]});
        }
        return result;
    }
};
// @lc code=end

