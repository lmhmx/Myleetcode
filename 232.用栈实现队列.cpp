/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
# include<stack>
using namespace std;
class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int ans = 0;
        if(!s2.empty())
        {
            ans = s2.top();
            s2.pop();
        }
        else if(s1.empty())
        {
            //error
        }
        else
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            ans = s2.top();
            s2.pop();
        }
        return ans;
    }
    
    int peek() {
        int ans = 0;
        if(!s2.empty())
        {
            ans = s2.top();
        }
        else if(s1.empty())
        {
            //error
        }
        else
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            ans = s2.top();
        }
        return ans;
    }
    
    bool empty() {
        return s1.empty()&&s2.empty();
    }
private:
    stack<int> s1;
    stack<int> s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

