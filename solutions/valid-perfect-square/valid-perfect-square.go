// @Title: Valid Perfect Square
// @Author: colinjxc
// @Date: 2022-03-05T22:20:25+08:00
// @URL: https://leetcode-cn.com/problems/valid-perfect-square


func isPerfectSquare(num int) bool {
    lo, hi := int64(0), int64(num)
    var square int64 = 0 
    for lo <= hi {
        mid := int64(lo + (hi - lo)/2)
        square = mid * mid
        if square > int64(num) {
            hi = mid -1
        } else if square < int64(num) {
            lo = mid + 1
        } else {
            return true
        }
    }
    return false
}
