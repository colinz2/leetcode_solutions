// @Title: 二进制中1的个数 LCOF
// @Author: colinjxc
// @Date: 2021-07-08T23:01:01+08:00
// @URL: https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum  = 0;
        while (n != 0) {
            sum++;
            n = n & (n -1);
        }
        return sum;
    }
};
