// @Title: Sort Array By Parity
// @Author: colinjxc
// @Date: 2022-02-05T14:52:57+08:00
// @URL: https://leetcode-cn.com/problems/sort-array-by-parity


class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        j = 0
        for i in range(len(nums)):
            if nums[i] % 2 == 0:
                nums[i], nums[j] = nums[j], nums[i]
                j += 1
        return nums
