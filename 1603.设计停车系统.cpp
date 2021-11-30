/*
 * @lc app=leetcode.cn id=1603 lang=cpp
 *
 * [1603] 设计停车系统
 */

// @lc code=start
class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        capacity[0] = big;
        capacity[1] = medium;
        capacity[2] = small;
        num[0] = 0;
        num[1] = 0;
        num[2] = 0;
    }
    
    bool addCar(int carType) {
        if(capacity[carType-1] == num[carType-1])
        {
            return false;
        }
        else
        {
            num[carType-1]++;
            return true;
        }
    }
private:
    int capacity[3];
    int num[3];
    
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// @lc code=end

