// @Title: Isomorphic Strings
// @Author: colinjxc
// @Date: 2021-07-17T20:23:34+08:00
// @URL: https://leetcode-cn.com/problems/isomorphic-strings


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int c1[256] = {0};
        int c2[256] = {0};
        
        if (s.size() != t.size()) {
            return false;
        }

        for (int i = 0; i < s.size(); i++) {
            if (c1[s[i]] != c2[t[i]]) {
                return false;
            }
            c1[s[i]] = i + 1;
            c2[t[i]] = i + 1;
        }

        return true;
    }
};
