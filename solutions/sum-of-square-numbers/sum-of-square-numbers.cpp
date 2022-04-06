// @Title: Sum of Square Numbers
// @Author: colinjxc
// @Date: 2018-12-06T21:26:32+08:00
// @URL: https://leetcode-cn.com/problems/sum-of-square-numbers


class Solution {
public:
    bool judgeSquareSum(int c) {
        int max = (int)sqrt(c) + 1;
        for (int i = 0; i < max; i++) {
            int square = i*i;
            int sub_sqrt = sqrt(c - square);
            if (sub_sqrt*sub_sqrt + square == c) return true;
        }
        return false;
    }
};
