/*
 * @lc app=leetcode.cn id=1360 lang=cpp
 *
 * [1360] 日期之间隔几天
 */

// @lc code=start
# include <string>
# include <vector>
using namespace std;

class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        vector<int> d1 = toDate(date1);
        vector<int> d2 = toDate(date2);
        int days1 = daysNum(d1);
        int days2 = daysNum(d2);
        return abs(days1-days2);
    }
private:
    vector<int> toDate(const string& s)
    {
        vector<int> d(3,0);
        d[0] = (s[0]-'0')*1000 + (s[1]-'0')*100+(s[2]-'0')*10+(s[3]-'0');
        d[1] = (s[5]-'0')*10 + (s[6]-'0');
        d[2] = (s[8]-'0')*10 + (s[9]-'0');
        return d;
    }
    // 从1年1月1日的天数
    int daysNum(const vector<int>& date)
    {
        int y = date[0];
        int m = date[1];
        int d = date[2];
        int month_days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int year_day = (y-1)*365 + (y-5)/4 - (y-101)/100 + (y-401)/400;
        int month_day = 0;
        for (int i=1;i<m;i++)
        {
            month_day += month_days[i-1];
        }
        month_day = month_day + ((m>2)&&(y%4==0&&(y%400==0 || y%100!=0)));
        int day_day = d;
        return year_day+month_day+day_day;
    }
};
// int main()
// {
//     Solution s;
//     s.daysBetweenDates("2100-09-22","1991-03-12");
//     s.daysBetweenDates("2000-09-12","2048-03-22");
//     return 0;
// }
// @lc code=end

