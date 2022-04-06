// @Title: Valid Anagram
// @Author: colinjxc
// @Date: 2021-07-17T13:05:11+08:00
// @URL: https://leetcode-cn.com/problems/valid-anagram


func isAnagram(s string, t string) bool {
    cntMap := make(map[rune]int)
    if len(s) != len(t) {
        return false
    }

    for _, c := range s {
        cntMap[c]++
    }

    for _, c := range t {
        cntMap[c]--
    }

    for _, v := range cntMap {
        if v != 0 {
            return false
        }
    }

    return true
}
