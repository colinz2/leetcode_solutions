// @Title: Arranging Coins
// @Author: colinjxc
// @Date: 2022-03-05T23:22:02+08:00
// @URL: https://leetcode-cn.com/problems/arranging-coins


class Solution {
public:
    // total = (n+1)*n / 2
    int arrangeCoins(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = (right - left + 1) / 2 + left;
            if ((long long) mid * (mid + 1) > (long long) 2 * n) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        return left;
    }
};
