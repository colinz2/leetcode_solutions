// @Title: 斐波那契数列  LCOF
// @Author: colinjxc
// @Date: 2022-01-25T20:02:07+08:00
// @URL: https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof


class Solution {
public:
    int fib(int n) {
        int MOD = 1000000007;
        vector<int> fibs(n+2);
        fibs[1] = 1;

        std::function<int(int)> fib_iter = [&](int n) {
            if (fibs[n] > 0 || n == 0) {
                return fibs[n];
            }
            int a = fib_iter(n-2) % MOD;
            int b = fib_iter(n-1) % MOD;
            fibs[n] = (a + b) % MOD;
            return fibs[n];
        };
        return fib_iter(n);
    }
};
