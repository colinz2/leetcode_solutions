// @Title: 替换空格 LCOF
// @Author: colinjxc
// @Date: 2021-07-23T12:39:46+08:00
// @URL: https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof


class Solution {
public:
    string replaceSpace(string s) {
        int cnt = 0, len = s.size();
        for (auto &c : s) {
            if (c == ' ') {
                cnt++;
            }
        }
        s.resize(len + 2*cnt);
        for (int i = s.size() - 1, j = len - 1;  i != j; i--, j-- ) {
            if (s[j] != ' ') {
                s[i] = s[j];
            } else {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;
            }
        }

        return s;
    }
};
