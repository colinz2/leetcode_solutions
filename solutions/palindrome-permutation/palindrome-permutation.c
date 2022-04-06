// @Title: Palindrome Permutation
// @Author: colinjxc
// @Date: 2022-02-01T03:35:08+08:00
// @URL: https://leetcode-cn.com/problems/palindrome-permutation


bool canPermutePalindrome(char * s){
    int seen[128] = {0,};
    while (*s) seen[*s++]++;

    int cnt = 0;
    for (int i = 0; i < sizeof(seen)/sizeof(seen[0]); i++) {
        cnt += seen[i] % 2;
        if (cnt > 1) return false;
    } 
    return true;
}
