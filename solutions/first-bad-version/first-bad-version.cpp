// @Title: First Bad Version
// @Author: colinjxc
// @Date: 2022-02-08T03:40:39+08:00
// @URL: https://leetcode-cn.com/problems/first-bad-version


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int j = 0, k = n;
        while (j < k) {
            int m = j + (k-j)/2;
            if (!isBadVersion(m)) {
                j = m + 1;
            } else {
                k = m;
            }
        }
        return k;
    }
};
