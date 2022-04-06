// @Title: Maximal Square
// @Author: colinjxc
// @Date: 2022-01-31T21:50:17+08:00
// @URL: https://leetcode-cn.com/problems/maximal-square


func maximalSquare(matrix [][]byte) int {
    m, n := len(matrix), len(matrix[0])
    max_width := 0
    dp := make([][]int, m)
    for i := 0; i < m; i++ {
        dp[i] = make([]int, n)
    }
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if matrix[i][j] == '1' {
                if i == 0 || j == 0 {
                    dp[i][j] = 1        
                } else {
                    dp[i][j] = min3(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
                }
                max_width = max(max_width, dp[i][j])
            }
        }
    }
    return max_width*max_width
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func min(a, b int) int {
    if a > b {
        return b
    }
    return a
} 

func min3(a, b, c int) int {
    res := min(a, b)
    res = min(res, c)
    return res
}
