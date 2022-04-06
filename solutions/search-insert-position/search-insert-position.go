// @Title: Search Insert Position
// @Author: colinjxc
// @Date: 2022-01-26T00:46:36+08:00
// @URL: https://leetcode-cn.com/problems/search-insert-position


func searchInsert(nums []int, target int) int {
    j, k := 0, len(nums)-1
    for j <= k {
        m := j + (k - j)/2
        if nums[m] == target {
            return m
        } else if nums[m] < target {
            j = m + 1
        } else {
            k = m - 1
        }
    }
    return j;
}
