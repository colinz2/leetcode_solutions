// @Title: To Lower Case
// @Author: colinjxc
// @Date: 2018-10-17T23:03:17+08:00
// @URL: https://leetcode-cn.com/problems/to-lower-case


class Solution {
public:
    string toLowerCase(string str) {
        for (auto &c : str) {
            c = tolower(c);
        }
        return str;
    }
};
