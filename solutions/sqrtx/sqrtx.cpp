// @Title: Sqrt(x)
// @Author: colinjxc
// @Date: 2022-02-08T10:13:48+08:00
// @URL: https://leetcode-cn.com/problems/sqrtx


class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int l = 0, r = x;
        while (l < r) {
            long long mid  = (l + r) / 2;
            if (mid * mid <= (long long)x) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return r-1;
    }
};
