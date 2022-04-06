// @Title: Move Zeroes
// @Author: colinjxc
// @Date: 2021-05-23T00:12:30+08:00
// @URL: https://leetcode-cn.com/problems/move-zeroes


func moveZeroes(nums []int) {
	k := 0
	for i := range nums {
		if nums[i] != 0 {
			if i != k {
				nums[i], nums[k] = nums[k], nums[i]
			}
			k++
		}
	}
}
