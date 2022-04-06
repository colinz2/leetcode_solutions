// @Title: Majority Element
// @Author: colinjxc
// @Date: 2021-05-20T02:18:35+08:00
// @URL: https://leetcode-cn.com/problems/majority-element


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        ans, count = 0, 0
        for x in nums:
            ans = x if count == 0  else ans
            count = count + 1 if ans == x else count - 1

        return ans
