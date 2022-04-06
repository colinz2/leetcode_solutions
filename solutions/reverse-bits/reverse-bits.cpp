// @Title: Reverse Bits
// @Author: colinjxc
// @Date: 2021-11-01T21:43:57+08:00
// @URL: https://leetcode-cn.com/problems/reverse-bits


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        for (int i = 0; i < 32 && n > 0; i++) {
            ret |=  (n & 1) << (31-i);
            n >>= 1;
        }
        return ret;
    }
};
