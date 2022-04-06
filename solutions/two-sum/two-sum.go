// @Title: Two Sum
// @Author: colinjxc
// @Date: 2022-02-09T16:35:49+08:00
// @URL: https://leetcode-cn.com/problems/two-sum


func twoSum(nums []int, target int) []int {
    seen := make(map[int]int)
    for i, num := range nums {
        if val, e := seen[target - num]; e {
            return []int{val, i}
        }
        seen[num] = i
    }
    return []int{-1, -1}
}
