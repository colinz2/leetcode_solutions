// @Title: Longest Common Subsequence
// @Author: colinjxc
// @Date: 2022-01-24T12:18:55+08:00
// @URL: https://leetcode-cn.com/problems/longest-common-subsequence


func longestCommonSubsequence(text1 string, text2 string) int {
    memo := make([][]int, len(text1) + 1)
    for i := 0; i < len(memo); i++ {
        memo[i] = make([]int, len(text2) + 1)
    }
    return getLcs(text1, text2, memo)
}

func getLcs(t1, t2 string, memo [][]int) int {
    len1, len2 := len(t1), len(t2)
    if len1 == 0 || len2 == 0 {
        return 0;
    }

    if memo[len1][len2] > 0 {
        return memo[len1][len2]
    }

    if t1[0] == t2[0] {
        return 1 + getLcs(t1[1:], t2[1:], memo)
    }
    
    memo[len1][len2] = max(getLcs(t1, t2[1:], memo), getLcs(t1[1:], t2, memo))
    return memo[len1][len2]
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
