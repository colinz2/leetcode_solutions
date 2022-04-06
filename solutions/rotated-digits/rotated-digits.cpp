// @Title: Rotated Digits
// @Author: colinjxc
// @Date: 2018-12-15T21:10:39+08:00
// @URL: https://leetcode-cn.com/problems/rotated-digits


class Solution {
public:
    int check_Digit(int n) {
        int rotate_map[10] = {0,1,5,-1,-1,2,9,-1,8,6};
        int n1 = 0;
        int n2 = 0;
        while (n) {
            int mod = n % 10;
            if (rotate_map[mod] < 0) return 0;
            n1 += n1 * 10 + mod;
            n2 += n2 * 10 + rotate_map[mod];
            n /= 10;
        }
        return (int)n1 != n2;
    }
    
    int rotatedDigits(int N) {
        int res = 0;
        while (N) {
            int x = check_Digit(N);
            res += x;
            N--;
        }
        return res;
    }
};
