// @Title: Sort Array By Parity
// @Author: colinjxc
// @Date: 2022-02-05T14:25:27+08:00
// @URL: https://leetcode-cn.com/problems/sort-array-by-parity


class Solution {
    public int[] sortArrayByParity(int[] A) {
        int i = 0, j = A.length - 1;
        while (i < j) {
            if (A[i] % 2 > A[j] % 2) {
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }

            if (A[i] % 2 == 0) i++;
            if (A[j] % 2 == 1) j--;
        }

        return A;
    }
}

