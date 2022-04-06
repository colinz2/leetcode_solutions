// @Title: Palindrome Permutation
// @Author: colinjxc
// @Date: 2022-02-01T03:08:54+08:00
// @URL: https://leetcode-cn.com/problems/palindrome-permutation


class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char, int> smap;
        for (auto& c : s) {
            smap[c]++;
        }
        int ocnt = 0;
        for (auto& p : smap) {
            ocnt += p.second % 2;
            if (ocnt > 1) {
                return false;
            }
        }
        return true;
    }
};
