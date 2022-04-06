// @Title: Majority Element
// @Author: colinjxc
// @Date: 2021-05-20T02:07:18+08:00
// @URL: https://leetcode-cn.com/problems/majority-element


func majorityElement(nums []int) int {
	res, count := nums[0], 0
	for i := 0; i < len(nums); i++ {
		if count == 0 {
			res, count = nums[i], 1
		} else {
			if nums[i] == res {
				count++
			} else {
				count--
			}
		}
	}
	return res
}
