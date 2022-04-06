// @Title: Power of Three
// @Author: colinjxc
// @Date: 2022-02-08T02:30:21+08:00
// @URL: https://leetcode-cn.com/problems/power-of-three


class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0) return false;
        #define log3(n)  log(n)/log(3)
        
        double x = log3(n);
        return abs(x - round(x)) < 1e-10;
    }
};


