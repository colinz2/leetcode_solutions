// @Title: Two Sum
// @Author: colinjxc
// @Date: 2021-10-25T14:03:21+08:00
// @URL: https://leetcode-cn.com/problems/two-sum


class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        check_dict = dict()
        for i, n in enumerate(nums):
            c = target - n
            if c in check_dict:
                return [check_dict[c], i]
            check_dict[n] = i
