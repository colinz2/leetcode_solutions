// @Title: Fibonacci Number
// @Author: colinjxc
// @Date: 2022-02-05T02:28:51+08:00
// @URL: https://leetcode-cn.com/problems/fibonacci-number


func fib(n int) int {
    if n < 2 {
        return n
    }
    return fib(n-1) + fib(n-2)
}
