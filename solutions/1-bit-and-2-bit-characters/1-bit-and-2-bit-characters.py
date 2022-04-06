// @Title: 1-bit and 2-bit Characters
// @Author: colinjxc
// @Date: 2022-02-02T17:01:24+08:00
// @URL: https://leetcode-cn.com/problems/1-bit-and-2-bit-characters


class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        i = len(bits) - 2
        while i >= 0 and bits[i] == 1:
            i -= 1
        return (len(bits)-2-i) % 2 ==  0
