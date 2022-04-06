// @Title: Counting Bits
// @Author: colinjxc
// @Date: 2021-07-17T23:43:57+08:00
// @URL: https://leetcode-cn.com/problems/counting-bits


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n + 1);
        for (int i = 1; i <= n; i++) {
            bits[i] = bits[i & (i - 1)] + 1;
        }
        return bits;
    }
};
