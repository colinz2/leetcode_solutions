// @Title: Binary Search
// @Author: colinjxc
// @Date: 2022-01-26T01:16:39+08:00
// @URL: https://leetcode-cn.com/problems/binary-search


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        i, j = 0, len(nums)
        while i < j:
            m = (i + j)//2
            if nums[m] == target:
                return m
            elif nums[m] < target:
                i = m + 1
            else:
                j = m

        return -1

