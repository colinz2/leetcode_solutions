// @Title: 数组中重复的数字 LCOF
// @Author: colinjxc
// @Date: 2021-07-19T13:15:19+08:00
// @URL: https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof


class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        seen = set()
        for n in nums:
            if n in seen:
                return n
            seen.add(n)
        return -1
