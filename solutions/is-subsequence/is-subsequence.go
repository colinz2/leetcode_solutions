// @Title: Is Subsequence
// @Author: colinjxc
// @Date: 2022-01-24T01:28:12+08:00
// @URL: https://leetcode-cn.com/problems/is-subsequence


func isSubsequence(s string, t string) bool {
    m, n := len(s), len(t)
    dp := make([][]int, m+1)
    for i := 0; i <= m; i++ {
        dp[i] = make([]int, n+1)
    }

    for i := 1; i <= m; i++ {
        for j := 1; j <= n; j++ {
            if s[i-1] == t[j-1] {
                dp[i][j] = dp[i-1][j-1] + 1
            } else {
                dp[i][j] = dp[i][j-1]
            }
        }
    }
    return dp[m][n] == len(s)
}
