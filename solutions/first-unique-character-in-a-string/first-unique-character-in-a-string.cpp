// @Title: First Unique Character in a String
// @Author: colinjxc
// @Date: 2018-12-15T14:09:08+08:00
// @URL: https://leetcode-cn.com/problems/first-unique-character-in-a-string


class Solution {
public:
    int firstUniqChar(string s) {
        int cnt[256] = {0};
        for (auto &c : s) {
            cnt[c] += 1;
        }
        for (int i = 0; i < s.size(); i++) {
            if (cnt[s[i]] == 1) return i;
        }
        return -1;
    }
};
