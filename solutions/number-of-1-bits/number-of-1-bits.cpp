// @Title: Number of 1 Bits
// @Author: realzhangm
// @Date: 2021-11-01T21:45:20+08:00
// @URL: https://leetcode-cn.com/problems/number-of-1-bits


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while (n > 0) {
            ret += (n & 1);
            n >>= 1;
        }
        return ret;
    }
};
