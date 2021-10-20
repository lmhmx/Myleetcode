/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] 设计循环双端队列
 */

// @lc code=start
# include <string>
# include <vector>
# include <list>
# include <iostream>
using namespace std;
class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        m_size = k;
    }
    
    bool insertFront(int value) {
        if(m_queqe.size()<m_size){
            m_queqe.push_front(value);
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(m_queqe.size()<m_size){
            m_queqe.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(m_queqe.size()!=0){
            m_queqe.pop_front();
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if(m_queqe.size()!=0){
            m_queqe.pop_back();
            return true;
        }
        return false;
    }
    
    int getFront() {
        if(m_queqe.size()==0){
            return -1;
        }
        return m_queqe.front();
    }
    
    int getRear() {
        if(m_queqe.size()==0){
            return -1;
        }
        return m_queqe.back();
    }
    
    bool isEmpty() {
        return m_queqe.size()==0;
    }
    
    bool isFull() {
        return m_queqe.size()==m_size;
    }
private:
    list<int> m_queqe;
    int m_size;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

