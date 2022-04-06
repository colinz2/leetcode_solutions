// @Title: Hamming Distance
// @Author: colinjxc
// @Date: 2018-10-15T20:20:18+08:00
// @URL: https://leetcode-cn.com/problems/hamming-distance


class Solution:
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        xor = x ^ y
        d = 0
        while xor > 0:
            d += xor & 1
            xor >>= 1
        return d
        
