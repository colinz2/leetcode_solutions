// @Title: Word Pattern
// @Author: colinjxc
// @Date: 2021-07-17T16:55:23+08:00
// @URL: https://leetcode-cn.com/problems/word-pattern


func wordPattern(pattern string, s string) bool {
    words := strings.Fields(s)
    if len(pattern) != len(words) {
        return false
    }
    seen := make(map[byte]int)
    seenWord := make(map[string]int)
    for i := 0; i < len(pattern); i++ {
        if seen[pattern[i]] != seenWord[words[i]] {
            return false
        }
        seen[pattern[i]] = i + 1
        seenWord[words[i]] = i + 1
    }
    return true
}
