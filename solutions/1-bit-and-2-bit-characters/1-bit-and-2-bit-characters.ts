// @Title: 1-bit and 2-bit Characters
// @Author: colinjxc
// @Date: 2022-02-02T18:39:03+08:00
// @URL: https://leetcode-cn.com/problems/1-bit-and-2-bit-characters


function isOneBitCharacter(bits: number[]): boolean {
    let i = bits.length - 2
    while (i >= 0 && bits[i] == 1)i--;
    return (bits.length - 2 - i) % 2 == 0

};
