// @Title: House Robber
// @Author: colinjxc
// @Date: 2022-01-06T15:36:19+08:00
// @URL: https://leetcode-cn.com/problems/house-robber


func rob(nums []int) int {
    pre := 0
    curr := 0
    for _, n := range nums {
        tmp := max(curr, pre + n)
        pre, curr = curr, tmp
    }
    return curr
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
