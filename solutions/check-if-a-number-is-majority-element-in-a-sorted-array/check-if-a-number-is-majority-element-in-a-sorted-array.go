// @Title: Check If a Number Is Majority Element in a Sorted Array
// @Author: colinjxc
// @Date: 2022-02-07T12:20:45+08:00
// @URL: https://leetcode-cn.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array


func isMajorityElement(nums []int, target int) bool {
    j , k := 0, len(nums)
    for j < k {
        m := (j+k)>>1
        if nums[m] < target {
            j = m + 1
        } else {
            k = m
        }
    }
    j += len(nums)/2
    return j < len(nums) && nums[j] == target
}
