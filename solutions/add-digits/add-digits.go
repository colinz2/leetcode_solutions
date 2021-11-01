// @Title: Add Digits
// @Author: realzhangm
// @Date: 2021-10-28T23:14:47+08:00
// @URL: https://leetcode-cn.com/problems/add-digits


func addDigits(num int) int {
    if num < 10 {
        return num
    }
    num = addD(num)
    return addDigits(num)
}

func addD(n int) int {
    sum := 0
    for n > 0 {
        sum += n%10
        n /= 10
    }
    return sum 
}
