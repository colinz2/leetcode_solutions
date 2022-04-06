// @Title: Length of Last Word
// @Author: colinjxc
// @Date: 2018-12-06T21:56:50+08:00
// @URL: https://leetcode-cn.com/problems/length-of-last-word


class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() < 1) return 0;
        int cnt =0;
        bool _space_end = true;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                _space_end = false;
                cnt++;
            } else if (_space_end) {
                continue;
            } else {
                break;
            }
        }
        return cnt;
    }
};
