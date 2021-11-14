# include <iostream>
# include <vector>
# include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        string ans;
        int row = 0;
        int col = 0;
        int last_begin_col =0;
        int cols = encodedText.size()/rows;
        while(1)
        {
            if(col==cols)
            {
                break;
            }
            ans.push_back(encodedText[col+row*cols]);
            if(col == cols-1)
            {
                row = 0;
            }
            else
            {
                row=(row+1)%rows;
            }
            col=col+1;
            if(row==0||col==cols)
            {
                col = last_begin_col+1;
                last_begin_col++;
            }

        }
        while(ans.back()==' ')
        {
            ans.pop_back();
        }
        return ans;
    }
};
