// @Title: Reverse String
// @Author: colinjxc
// @Date: 2018-11-28T20:27:38+08:00
// @URL: https://leetcode-cn.com/problems/reverse-string


class Solution {
public:
    string reverseString(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            std::swap(s[l++], s[r--]);
        }
        return s;
    }
};
