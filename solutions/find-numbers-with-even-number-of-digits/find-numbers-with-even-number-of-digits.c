// @Title: Find Numbers with Even Number of Digits
// @Author: colinjxc
// @Date: 2021-10-27T19:07:43+08:00
// @URL: https://leetcode-cn.com/problems/find-numbers-with-even-number-of-digits


inline int isEven(int n) {
    int cnt = 1;
    while (n /= 10) {
        cnt++;
    }
    return cnt % 2 == 0 ? 1 : 0;
}

int findNumbers(int* nums, int numsSize){
    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        res += isEven(nums[i]);
    }
    return res;
}
