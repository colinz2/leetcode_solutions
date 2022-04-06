// @Title: Find the Difference
// @Author: colinjxc
// @Date: 2022-01-26T19:12:08+08:00
// @URL: https://leetcode-cn.com/problems/find-the-difference


class Solution {
public:
    char findTheDifference(string s, string t) {
        char c = 0;
        // or s + t
        for (int i = 0; i < s.size(); i++) {
            c ^= s[i] ^ t[i]; 
        }
        return t.back() ^ c;
    }
};
