// @Title: Hamming Distance
// @Author: colinjxc
// @Date: 2022-04-01T22:10:54+08:00
// @URL: https://leetcode-cn.com/problems/hamming-distance


class Solution {
public:
    int hammingDistance(int x, int y) {
        int distance = 0;
        int z = x ^ y;
        while (z) {
            distance += (z & 0x01);
            z >>= 1;
        }
        return distance;              
    }
};
