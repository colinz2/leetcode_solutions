// @Title: Count Binary Substrings
// @Author: colinjxc
// @Date: 2022-02-03T03:07:32+08:00
// @URL: https://leetcode-cn.com/problems/count-binary-substrings


class Solution {
public:
    int countBinarySubstrings(string s) {
        int pre_cnt = 0, curr_cnt = 1;
        int res = 0;

        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == s[i]) {
                curr_cnt++;
            } else {
                pre_cnt = curr_cnt;
                curr_cnt = 1;
            }
            if (pre_cnt >= curr_cnt) {
                res++;
            }
        }

        return res;
    }
};
