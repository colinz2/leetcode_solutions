// @Title: Valid Perfect Square
// @Author: colinjxc
// @Date: 2022-03-05T22:14:22+08:00
// @URL: https://leetcode-cn.com/problems/valid-perfect-square


class Solution {
public:
    bool isPerfectSquare(int num) {
        long square = 1, n = 1;
        while (square <= num) {
            square = n*n;
            if (square == num) return true;
            n++;
        }
        return false;
    }
};
