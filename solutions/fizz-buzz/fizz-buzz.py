// @Title: Fizz Buzz
// @Author: colinjxc
// @Date: 2022-04-04T20:55:56+08:00
// @URL: https://leetcode-cn.com/problems/fizz-buzz


class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        res = []
        i = 1
        while i <= n:
            if i % 15 == 0:
                res.append("FizzBuzz")
            elif i % 5 == 0:
                res.append("Buzz")
            elif i % 3 == 0:
                res.append("Fizz")
            else:
                res.append(str(i))
            i += 1
        return res

