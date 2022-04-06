// @Title: Longest Palindrome
// @Author: colinjxc
// @Date: 2022-02-01T03:59:10+08:00
// @URL: https://leetcode-cn.com/problems/longest-palindrome


int longestPalindrome(char * s){
    int seen[128] = {0,};
    int strlen = 0;
    while (*s) seen[*s++]++, strlen++;
    int ocnt = 0;
    for (int i = 'a'; i <= 'z'; i++) {
        ocnt += seen[i] % 2;
    }
    for (int i = 'A'; i <= 'Z'; i++) {
        ocnt += seen[i] % 2;
    }
    if (ocnt > 0) ocnt--;
    
    return strlen - ocnt;
}
