// @Title: Count Primes
// @Author: colinjxc
// @Date: 2022-02-07T17:50:43+08:00
// @URL: https://leetcode-cn.com/problems/count-primes


class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrimeVec(n, 1);
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrimeVec[i]) {
                count++;
                for (int j = 2 * i; j < n; j += i) {
                    isPrimeVec[j] = 0;
                }
            }
        }
        return count;
    }
};
