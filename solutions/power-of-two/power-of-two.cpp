// @Title: Power of Two
// @Author: colinjxc
// @Date: 2022-02-09T20:56:37+08:00
// @URL: https://leetcode-cn.com/problems/power-of-two


class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};
