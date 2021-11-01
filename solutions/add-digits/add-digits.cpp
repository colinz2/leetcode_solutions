// @Title: Add Digits
// @Author: realzhangm
// @Date: 2021-10-29T11:23:21+08:00
// @URL: https://leetcode-cn.com/problems/add-digits


class Solution {
public:
    int addDigits(int num) {
        int n = num;
        int next = 0;
        while (n > 9) {
            while (n > 0) {
                next += n % 10;
                n  /= 10;
            }
            n = next;
            next = 0;
        }
        return n;
    }
};
