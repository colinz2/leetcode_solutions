// @Title: Guess Number Higher or Lower
// @Author: colinjxc
// @Date: 2022-01-26T15:15:00+08:00
// @URL: https://leetcode-cn.com/problems/guess-number-higher-or-lower


/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int j = 1, k = n;
        while (j <= n) {
            int m = j + (k - j)/2;
            int ret = guess(m);
            if (ret == 0) {
                return m;
            } else if (ret == 1) {
                j = m + 1;
            } else if (ret == -1) {
                k = m - 1;
            } else {
                break;
            }
        } 
        return -1;
    }
};
