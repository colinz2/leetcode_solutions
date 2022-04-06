// @Title: Spiral Matrix
// @Author: colinjxc
// @Date: 2022-02-02T21:44:51+08:00
// @URL: https://leetcode-cn.com/problems/spiral-matrix


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        while matrix:
            res += matrix.pop(0)
            # zip * 解包运算符. like zip(a, b)
            matrix = list(zip(*matrix))[::-1]
        return res
