/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
# include <string>
# include <vector>
# include <iostream>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        vector<char> operator_char;
        vector<int> numbers;
        
        string currentNumber;
        int currentResult = 0;
        numbers.push_back(0);
        operator_char.push_back('+');
        s.append("+0 ");
        for (int i = 0;i<s.size();i++){
            if(s[i] == ' '){
                if(currentNumber.size() > 0){
                    numbers.push_back(atoi(currentNumber.c_str()));
                    currentNumber.clear();
                }
            }
            else if('0' <= s[i] && s[i] <= '9'){
                currentNumber.push_back(s[i]);
            }
            else{
                if(currentNumber.size()>0){
                    numbers.push_back(atoi(currentNumber.c_str()));
                    currentNumber.clear();
                }
                operator_char.push_back(s[i]);
                while(1){
                    if(operator_char.size()>1){
                        if(compare(operator_char[operator_char.size()-2],operator_char[operator_char.size()-1])>=0)
                        {
                            char op;
                            int n1;
                            int n2;
                            int r_tmp;
                            operator_char.pop_back();
                            op=operator_char.back();
                            operator_char.pop_back();
                            operator_char.push_back(s[i]);
                            n2=numbers.back();
                            numbers.pop_back();
                            n1=numbers.back();
                            numbers.pop_back();
                            r_tmp = calculate(n1,op,n2);
                            numbers.push_back(r_tmp);
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return calculate(numbers[0],operator_char[0],numbers[1]);
    }
private:
    int compare(char a, char b){
        int a_level = level_of_operator(a);
        int b_level = level_of_operator(b);
        return a_level-b_level;
    }
    int level_of_operator(char c){
        if(c == '-' || c == '+'){
            return 1;
        }
        else if (c=='*'|| c== '/'){
            return 2;
        }
        return 0;
    }
    int calculate(int n1, char c, int n2){
        if(c == '+'){
            return n1+n2;
        }
        else if(c=='-'){
            return n1-n2;
        }
        else if(c=='*'){
            return n1*n2;
        }
        else if(c=='/'){
            return n1/n2;
        }
        return 0;
    }
};
// int main(){
//     Solution s;
//     cout << s.calculate(" 3+ 5 / 2 ");
// }
// @lc code=end

