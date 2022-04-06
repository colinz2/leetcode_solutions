// @Title: Number of Segments in a String
// @Author: colinjxc
// @Date: 2018-12-05T12:18:04+08:00
// @URL: https://leetcode-cn.com/problems/number-of-segments-in-a-string


class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) 
            res += s[i] != ' ' && (i + 1 == s.size() || s[i + 1] == ' ');
        return res;
    }
};


