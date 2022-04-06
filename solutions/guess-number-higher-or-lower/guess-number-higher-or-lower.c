// @Title: Guess Number Higher or Lower
// @Author: colinjxc
// @Date: 2022-02-08T04:07:25+08:00
// @URL: https://leetcode-cn.com/problems/guess-number-higher-or-lower


/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n){
    int lo = 0, hi = n;
    while (lo <= hi) {
        int m = lo + (hi - lo) / 2;
        int ret = guess(m);
        if (ret == 1) {
            lo = m + 1;
        } else if (ret == -1) {
            hi = m - 1;
        } else {
            return m;
        }
    }
    return -1;
}
