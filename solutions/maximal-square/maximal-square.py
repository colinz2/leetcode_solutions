// @Title: Maximal Square
// @Author: colinjxc
// @Date: 2022-01-31T21:37:12+08:00
// @URL: https://leetcode-cn.com/problems/maximal-square


class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        m = len(matrix)
        n = len(matrix[0])
        max_width =  0
        dp = [[0]*n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == '1':
                    if i == 0 or j == 0:
                        dp[i][j] = 1
                    else: 
                        dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
                    max_width = max(max_width, dp[i][j])
                else:
                    dp[i][j] = 0
        return max_width * max_width
