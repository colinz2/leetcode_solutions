// @Title: Fibonacci Number
// @Author: colinjxc
// @Date: 2022-02-05T02:44:37+08:00
// @URL: https://leetcode-cn.com/problems/fibonacci-number


class Solution:
    def fib(self, n: int) -> int:
        return int((5**0.5)*0.2*( ((1+5**0.5)/2)**n-((1-5**0.5)/2)**n))
