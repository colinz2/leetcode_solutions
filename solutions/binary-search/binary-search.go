// @Title: Binary Search
// @Author: colinjxc
// @Date: 2022-02-02T20:41:45+08:00
// @URL: https://leetcode-cn.com/problems/binary-search


func search(nums []int, target int) int {
    j, k := 0, len(nums)
    for j < k {
        m := (j + k) >> 1
        if nums[m] < target {
            j = m + 1
        } else if (nums[m] > target) {
            k = m
        } else {
            return m
        }
    }
    return -1
}
