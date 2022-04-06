// @Title: Divide Two Integers
// @Author: colinjxc
// @Date: 2022-02-07T18:02:03+08:00
// @URL: https://leetcode-cn.com/problems/divide-two-integers


class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        return dividend / divisor;
    }
};
