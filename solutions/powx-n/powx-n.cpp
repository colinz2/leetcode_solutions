// @Title: Pow(x, n)
// @Author: colinjxc
// @Date: 2022-02-10T01:30:11+08:00
// @URL: https://leetcode-cn.com/problems/powx-n


class Solution {
public:
    double quickMul(double x, long long N) {
        if (N == 0) {
            return 1.0;
        }
        double y = quickMul(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }

    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};
