/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 */

// @lc code=start
# include <string>
# include <vector>
# include <list>
# include <iostream>
# include <queue>
# include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>> img = image;
        int rows = img.size();
        int cols = img[0].size();
        for (int row =0;row < rows;row++){
            for (int col = 0;col<cols;col++){
                img[row][col] = 1-image[row][rows-1-col];
            }
        }
        return img;
    }   
};
// @lc code=end

