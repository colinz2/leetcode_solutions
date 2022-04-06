// @Title: 数组中重复的数字 LCOF
// @Author: colinjxc
// @Date: 2021-07-19T13:12:57+08:00
// @URL: https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof


func findRepeatNumber(nums []int) int {
    seen := make(map[int]struct{})
    for _, n := range nums {
        if _, e := seen[n]; e {
            return n
        }
        seen[n] = struct{}{}
    }
    return -1
}
