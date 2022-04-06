// @Title: Find Smallest Letter Greater Than Target
// @Author: colinjxc
// @Date: 2022-02-07T23:46:36+08:00
// @URL: https://leetcode-cn.com/problems/find-smallest-letter-greater-than-target


func nextGreatestLetter(letters []byte, target byte) byte {
    lo, hi := 0, len(letters)
    for lo < hi {
        m := (lo + hi) >> 1
        if letters[m] <= target {
            lo = m + 1
        } else {
            hi = m
        }
    }
    if lo == len(letters) {
        lo = 0
    }
    return letters[lo]
}
