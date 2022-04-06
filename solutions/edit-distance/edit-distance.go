// @Title: Edit Distance
// @Author: colinjxc
// @Date: 2022-01-24T00:33:39+08:00
// @URL: https://leetcode-cn.com/problems/edit-distance


func minDistance(word1 string, word2 string) int {
    memo := make([][]int, len(word1) + 1)
    for i := 0; i < len(memo); i++ {
        memo[i] = make([]int, len(word2) + 1)
    }
    return edit(word1, word2, memo)
}

// 编辑剩下的字符串
// 增加记忆化
func edit(w1 string, w2 string, memo [][]int) int {
    if len(w1) == 0 || len(w2) == 0 {
        return len(w2) + len(w1)
    }

    if w1[0] == w2[0] {
        return edit(w1[1:], w2[1:], memo)
    } 

    if memo[len(w1)][len(w2)] != 0 {
        return memo[len(w1)][len(w2)]
    }

    del := 1 + edit(w1[1:], w2[:], memo)
    add := 1 + edit(w1[:], w2[1:], memo)
    sub := 1 + edit(w1[1:], w2[1:], memo)
    memo[len(w1)][len(w2)] = min(del, add, sub)
    return memo[len(w1)][len(w2)]
}

func min(a, b, c int) int {
    if a < b {
        if a < c {
            return a
        } else {
            return c
        }
    } else if (b < c) {
        return b
    } 
    return c
} 
