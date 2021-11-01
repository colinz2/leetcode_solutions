// @Title: Add Digits
// @Author: realzhangm
// @Date: 2021-10-29T11:10:19+08:00
// @URL: https://leetcode-cn.com/problems/add-digits


class Solution:
    def addDigits(self, num: int) -> int:
        if num < 10:
            return num
        next = 0
        while num > 0:
            next += num%10
            num = num//10
        return self.addDigits(next)
