// @Title: Is Unique LCCI
// @Author: colinjxc
// @Date: 2022-01-25T19:09:06+08:00
// @URL: https://leetcode-cn.com/problems/is-unique-lcci


class Solution {
public:
    bool isUnique(string astr) {
        bool e[256] = {false,};
        for (auto& c : astr) {
            if (e[c]) {
                return false;
            }
            e[c] = true;
        }
        return  true;
    }
};
