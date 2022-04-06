// @Title: Happy Number
// @Author: colinjxc
// @Date: 2021-07-17T15:06:40+08:00
// @URL: https://leetcode-cn.com/problems/happy-number


class Solution {
public:
    bool isHappy(int n) {
        int next = n;
        unordered_set<int> seen;
        
        while (next != 1) {
            next = cal(next);
            if (seen.find(next) != seen.end()) {
                return false;
            }
            seen.insert(next);
        }
        return true;
    }
                                        
private:                                        
    int cal(int n) {
        int res = 0;
        while (n > 0) {
            int nn = n % 10;
            res += nn * nn;                                                                    
            n = n / 10;
        }
        return res;
    }                                   
};
