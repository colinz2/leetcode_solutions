// @Title: Add Digits
// @Author: realzhangm
// @Date: 2021-10-29T10:58:19+08:00
// @URL: https://leetcode-cn.com/problems/add-digits


impl Solution {
    pub fn add_digits(num: i32) -> i32 {
        (num - 1) % 9 + 1
    }
}
