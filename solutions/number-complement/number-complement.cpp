// @Title: Number Complement
// @Author: colinjxc
// @Date: 2022-01-26T14:51:31+08:00
// @URL: https://leetcode-cn.com/problems/number-complement


class Solution {
public:
    int findComplement(int num) {
        int f = 1;
        // find (2^n -1), n is highest bit 
        while (f < num) {
            f <<= 1;
            f++;
        }
        return f ^ num; // or return f & (~num);
    }
};
