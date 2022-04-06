// @Title: Is Subsequence
// @Author: colinjxc
// @Date: 2022-02-09T18:10:49+08:00
// @URL: https://leetcode-cn.com/problems/is-subsequence


bool isSubsequence(char * s, char * t){
    while (*s && *t) s += (*s == *t++);
    return !*s;
}
