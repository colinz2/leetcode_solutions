// @Title: Is Subsequence
// @Author: colinjxc
// @Date: 2022-02-09T20:33:31+08:00
// @URL: https://leetcode-cn.com/problems/is-subsequence


class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index = 0;
        for (auto c : t) {
            if (index < s.size() && c == s[index]) {
                index++;
            }
        }
        return index == s.size();
    }
};
