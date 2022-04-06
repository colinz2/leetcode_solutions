// @Title: Power of Three
// @Author: colinjxc
// @Date: 2022-02-08T01:44:18+08:00
// @URL: https://leetcode-cn.com/problems/power-of-three




bool isPowerOfThree(int n){
    long t = 1;
    while (t < n) {
        t *= 3;
    }
    return n == t;
}
