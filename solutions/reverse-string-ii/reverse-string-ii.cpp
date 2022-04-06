// @Title: Reverse String II
// @Author: colinjxc
// @Date: 2018-12-15T18:53:37+08:00
// @URL: https://leetcode-cn.com/problems/reverse-string-ii


class Solution {
public:
    string reverseStr(string s, int k) {
        int k2 = 2*k;
        int r = 0, l = 0, m = 0; //[l,m) [m, r)
        for (int i = 0; i < s.size(); i = r) {
            int last = s.size() - i;
            if (last >= k) {
                m = i + k;
                r = i + min(k2, last);
            } else {
                m = i + last;
                r = i + last;
            }
            l = i;
            while (l + 1 < m) {
                swap(s[l++], s[--m]);
            }
        }
        return s;
    }
};
