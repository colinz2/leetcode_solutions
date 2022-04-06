// @Title: Student Attendance Record I
// @Author: colinjxc
// @Date: 2018-12-15T19:44:59+08:00
// @URL: https://leetcode-cn.com/problems/student-attendance-record-i


class Solution {
public:
    bool checkRecord(string s) {
        int record[256] = {0, };

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            record[c] += 1;
            if (c == 'L') {
                if (record[c] > 2) return false;
                if (c != s[i + 1]) record[c] = 0;
            } else if (c == 'A') {
                if (record[c] > 1) return false;
            }
        }
        return true;
    }
};
