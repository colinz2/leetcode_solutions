// @Title: Reverse Integer
// @Author: realzhangm
// @Date: 2021-11-01T22:26:56+08:00
// @URL: https://leetcode-cn.com/problems/reverse-integer


class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        while (x != 0) {
            // 这里不用判断取余了，因为 x 也是 int
            if (ret > INT_MAX/10 || ret  < INT_MIN/10) {
                return 0;
            }
            ret = ret * 10 + x%10;
            x /= 10;
        }
        return ret;
    }
};
