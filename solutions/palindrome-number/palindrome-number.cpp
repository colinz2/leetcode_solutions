// @Title: Palindrome Number
// @Author: colinjxc
// @Date: 2018-11-13T23:21:28+08:00
// @URL: https://leetcode-cn.com/problems/palindrome-number


class Solution {
public:
    bool isPalindrome(int x) {
        long long ret = 0;
        long long y = x;
        while (x != 0) {
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        return y == ret && y >= 0;
    }
};
