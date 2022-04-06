// @Title: Reverse Only Letters
// @Author: colinjxc
// @Date: 2022-02-23T10:05:31+08:00
// @URL: https://leetcode-cn.com/problems/reverse-only-letters


class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (!isalpha(s[i])) {
                i++;
                continue;
            }
            if (!isalpha(s[j])) {
                j--;
                continue;
            }
            std::swap(s[i++], s[j--]);
        }
        return s;
    }
};
