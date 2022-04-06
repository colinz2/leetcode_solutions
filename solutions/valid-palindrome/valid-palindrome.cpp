// @Title: Valid Palindrome
// @Author: colinjxc
// @Date: 2018-11-28T20:52:42+08:00
// @URL: https://leetcode-cn.com/problems/valid-palindrome


class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (!isalnum(s[l])) {
                l++;
                continue;
            }

            if (!isalnum(s[r])) {
                r--;
                continue;
            }

            if (toupper(s[l]) != toupper(s[r])) {
                return false;
            }
            
            l++;
            r--;
        }
        return true;
    }
};
