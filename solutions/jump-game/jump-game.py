// @Title: Jump Game
// @Author: colinjxc
// @Date: 2022-01-28T04:01:36+08:00
// @URL: https://leetcode-cn.com/problems/jump-game


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n, far_most = len(nums), 0
        for i in range(n):
            if i <= far_most:
                far_most = max(far_most, i + nums[i])
                if far_most + 1 >= len(nums):
                    return True
            else:
                break
        return False
