// @Title: Reverse Words in a String III
// @Author: colinjxc
// @Date: 2018-12-15T23:31:22+08:00
// @URL: https://leetcode-cn.com/problems/reverse-words-in-a-string-iii


class Solution {
private:
    void reverse(string& s, int l, int r) {
        //[l, r]
        while (l < r) {
            swap(s[l++], s[r--]);
        }
    }

public:
    string reverseWords(string s) {
        int b = 0, e = 0;
        for (int i = 0; i < s.size(); i++) {
            while (isblank(s[i])) {
                i++;
                b = i;
            }
            if (i + 1 == s.size() || isblank(s[i + 1])) {
                e = i;
                reverse(s, b, e);
            }
        }
        return s;
    }
};
