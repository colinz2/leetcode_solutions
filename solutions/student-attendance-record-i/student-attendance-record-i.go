// @Title: Student Attendance Record I
// @Author: colinjxc
// @Date: 2018-12-15T21:53:46+08:00
// @URL: https://leetcode-cn.com/problems/student-attendance-record-i


func checkRecord(s string) bool {
    l, a := 0, 0
    for i := 0; i < len(s); i++ {
        if (s[i] == 'L') {
            l += 1
        } else if (s[i] == 'A') {
            l = 0;
            a += 1
        } else {
            l = 0;
        }
        
        if l > 2 || a > 1 {
            return false
        }
    }
    return true
}
