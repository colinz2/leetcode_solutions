// @Title: Find Smallest Letter Greater Than Target
// @Author: colinjxc
// @Date: 2022-02-08T04:14:04+08:00
// @URL: https://leetcode-cn.com/problems/find-smallest-letter-greater-than-target


class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo = 0, hi = letters.size();
        while (lo < hi) {
            int m = (lo + hi) >> 1;
            if (letters[m] <= target) {
                lo = m + 1;
            } else {
                hi = m;
            }
        }
        if (hi == letters.size()) hi = 0;
        return letters[hi];
    }
};
