// @Title: Fibonacci Number
// @Author: colinjxc
// @Date: 2022-02-09T23:06:08+08:00
// @URL: https://leetcode-cn.com/problems/fibonacci-number


int fib(int n) {
    int fibs[2] = {0, 1, };
    while (n > 1) {
        fibs[0] = fibs[0] + fibs[1];
        fibs[1] = fibs[0] + fibs[1];
        n -= 2;
    }
    return fibs[n]; 
}
