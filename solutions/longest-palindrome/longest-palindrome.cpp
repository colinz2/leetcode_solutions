// @Title: Longest Palindrome
// @Author: colinjxc
// @Date: 2022-02-07T18:43:15+08:00
// @URL: https://leetcode-cn.com/problems/longest-palindrome


class Solution {
public:


    int longestPalindrome(string s) {

        int n = s.size();
        if (n == 0) return 0;
        int table[52] = {0};
            
        for (int i = 0; i < n; i++)
        {
            int index = int(s[i] - 'A');
            if (s[i] >= 'a')    index -= 6;
            table[index]++;
        }

        int even = 0;
        int odd = 0;
        for (int i = 0; i < 52; i++)
        {
            even += table[i] / 2 * 2;
            odd += table[i] % 2;     
        }
        
        odd = odd > 0 ? 1: 0;
        return even + odd;
    }
};
