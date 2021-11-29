/*
 * @lc app=leetcode.cn id=706 lang=cpp
 *
 * [706] 设计哈希映射
 */

// @lc code=start
# include <unordered_map>
using namespace std;
class MyHashMap {
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        hasMap[key]=value;
        // if(hasMap.count(key))
        // {
        //     hasMap[key]=value;
        // }
        // else
        // {
        //     hasMap.insert({key,value});
        // }
    }
    
    int get(int key) {
        if(hasMap.count((key)))
        {
            return hasMap[key];
        }
        return -1;
    }
    
    void remove(int key) {

        hasMap.erase(key);
    }
private:
    unordered_map<int,int> hasMap;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

