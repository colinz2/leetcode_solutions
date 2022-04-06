// @Title: Gray Code
// @Author: colinjxc
// @Date: 2022-02-02T15:11:43+08:00
// @URL: https://leetcode-cn.com/problems/gray-code


class Solution:
    def grayCode(self, n: int) -> List[int]: 
        return [i^(i >> 1) for i in range(1 << n)]
