// @Title: One Edit Distance
// @Author: colinjxc
// @Date: 2022-02-06T01:30:24+08:00
// @URL: https://leetcode-cn.com/problems/one-edit-distance


class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        // let len of s > t
        int distance = s.size() - t.size();
        if (distance < 0) {
            return isOneEditDistance(t, s);
        }
        if (distance > 1) {
            return false;
        }

        int len = t.size();
        for (int i = 0; i < len; i++) {
            if (s[i] != t[i]) {
                if (distance > 0) {
                    return s.substr(i+1) == t.substr(i);
                } else {
                    return s.substr(i+1) == t.substr(i+1);
                }
            }
        }
        return distance > 0;
    }
};
