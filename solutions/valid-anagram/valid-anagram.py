// @Title: Valid Anagram
// @Author: colinjxc
// @Date: 2021-07-17T12:20:32+08:00
// @URL: https://leetcode-cn.com/problems/valid-anagram


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)
