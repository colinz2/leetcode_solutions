// @Title: Guess Number Higher or Lower
// @Author: realzhangm
// @Date: 2021-10-30T22:23:23+08:00
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
        int l = 1, r = n;
        while (l <= r) {
            int mid = l + (r - l)/2;
            int ret = guess(mid);
            if (ret == -1) {
                r = mid - 1;
            } else if (ret == 1) {
                l = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
