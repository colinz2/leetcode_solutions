// @Title: Permutations
// @Author: colinjxc
// @Date: 2022-03-19T04:59:54+08:00
// @URL: https://leetcode-cn.com/problems/permutations


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        def backtrack(nums, tmp):
            if not nums:
                res.append(tmp)
                return 
            for i in range(len(nums)):
                backtrack(nums[:i] + nums[i+1:], tmp + [nums[i]])
                
        backtrack(nums, [])
        return res

