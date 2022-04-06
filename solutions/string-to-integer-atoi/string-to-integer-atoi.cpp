// @Title: String to Integer (atoi)
// @Author: colinjxc
// @Date: 2021-11-01T22:32:00+08:00
// @URL: https://leetcode-cn.com/problems/string-to-integer-atoi


class Solution {
public:
    int myAtoi(string s) {
        auto begin_pos = s.find_first_not_of(" \t\n\r");
        if (begin_pos == string::npos) return 0;

        int neg = 1;
        if (s[begin_pos] == '-') {
            neg = -1;
            begin_pos++;
        } else if (s[begin_pos] == '+') {
            neg = 1;
            begin_pos++;
        }

        int ret = 0;
        for (auto i = begin_pos; i < s.size(); i++) {
            int n = s[i];
            if (n < '0' || n > '9') break;

            if (ret > INT_MAX / 10 || (ret == INT_MAX /10 && (n - '0') > INT_MAX %10 )) return INT_MAX;
            if (ret < INT_MIN / 10 || (ret == INT_MIN /10 && ('0' - n) < INT_MIN %10)) return INT_MIN;
            
            ret = ret * 10 + neg * (n - '0');
        }

        return ret;
    }
};
