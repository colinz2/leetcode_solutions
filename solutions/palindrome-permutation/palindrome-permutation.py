// @Title: Palindrome Permutation
// @Author: colinjxc
// @Date: 2022-02-01T03:26:00+08:00
// @URL: https://leetcode-cn.com/problems/palindrome-permutation


class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        seen = collections.defaultdict(int)
        for c in s:
            seen[c] += 1
        cnt = 0
        for v in seen.values():
            cnt += v % 2
            if cnt > 1:
                return False
        return True
