// @Title: First Bad Version
// @Author: realzhangm
// @Date: 2021-10-30T21:39:02+08:00
// @URL: https://leetcode-cn.com/problems/first-bad-version


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    // the first version must in [earlyVer, latestVer]
    int firstBadVersion(int n) {
        int earlyVer = 1, latestVer = n;
        while (latestVer != earlyVer) {
            int checkVer = earlyVer + (latestVer - earlyVer) / 2;
            // check the middle versoin
            // if checkVer is bad, then the checkVer become the latestVer
            // if checkVer no bad, then the checkVer + 1 become the earlyVer
            
            if (isBadVersion(checkVer)) {
                latestVer = checkVer;
            } else {
                earlyVer = checkVer + 1;
            }
        }
        return earlyVer;
    }
};
