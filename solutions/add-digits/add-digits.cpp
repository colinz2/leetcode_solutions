// @Title: Add Digits
// @Author: colinjxc
// @Date: 2022-01-26T19:52:24+08:00
// @URL: https://leetcode-cn.com/problems/add-digits


class Solution {
public:
    int addDigits(int num) {
        while (num > 9) {
            int res = 0;
            while (num > 0) {
                res += num%10;
                num /= 10;
            }
            num = res;
        }
        return num;
    }
};
