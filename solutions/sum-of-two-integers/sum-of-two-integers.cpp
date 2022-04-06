// @Title: Sum of Two Integers
// @Author: colinjxc
// @Date: 2018-10-18T15:53:22+08:00
// @URL: https://leetcode-cn.com/problems/sum-of-two-integers


class Solution {
public:
    int getSum(int a, int b) {
        //使用符号了
        //return a + b;
        int sum = a;
        while (b != 0) {
            sum = a ^ b;//calculate sum of a and b without thinking the carry 
            b = (a & b) << 1;//calculate the carry
            a = sum;//add sum(without carry) and carry
        }
        return sum;
    }
};
