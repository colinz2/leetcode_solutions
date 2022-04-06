// @Title: Add Digits
// @Author: colinjxc
// @Date: 2022-01-26T21:01:01+08:00
// @URL: https://leetcode-cn.com/problems/add-digits


func addDigits(num int) int {
    if num > 9 {
        return addDigits(func(n int) int {
            res := 0
            for n > 0 {
                res += n % 10
                n /= 10
            }
            return res
        }(num))
    }
    return num
}
