// @Title: Fibonacci Number
// @Author: colinjxc
// @Date: 2022-02-09T23:13:04+08:00
// @URL: https://leetcode-cn.com/problems/fibonacci-number


class Solution {
public:
    int fib(int n) {
        int fb[3] = {0, 1};
        for (int i = 1; i <= n; i++) {
            fb[0] = fb[1];
            fb[1] = fb[2];
            fb[2] = fb[0] + fb[1];
        }
        return fb[2];
    }
};
