// @Title: 1-bit and 2-bit Characters
// @Author: colinjxc
// @Date: 2022-02-02T18:45:43+08:00
// @URL: https://leetcode-cn.com/problems/1-bit-and-2-bit-characters


bool isOneBitCharacter(int* bits, int bitsSize){
    int i = bitsSize - 2;
    while (i >= 0 && bits[i] == 1)i--;
    return (bitsSize-2-i) % 2 == 0;
}
