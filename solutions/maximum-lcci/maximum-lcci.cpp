// @Title: Maximum LCCI
// @Author: colinjxc
// @Date: 2021-10-24T01:28:32+08:00
// @URL: https://leetcode-cn.com/problems/maximum-lcci


class Solution {
public:
    int maximum(int a, int b) {
        long _sum = long(a) + long(b);
        long _diff = long(a) - long(b);
        long _abs_diff = (_diff ^ (_diff >> 63)) - (_diff >> 63);
        return (_sum + _abs_diff) / 2;
    }
};
