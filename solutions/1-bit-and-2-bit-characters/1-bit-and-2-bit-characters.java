// @Title: 1-bit and 2-bit Characters
// @Author: colinjxc
// @Date: 2022-02-02T18:32:02+08:00
// @URL: https://leetcode-cn.com/problems/1-bit-and-2-bit-characters


class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int i = 0;
        while (i < bits.length - 1) {
            i += bits[i] + 1;
        }
        return i == bits.length - 1;
    }
}
