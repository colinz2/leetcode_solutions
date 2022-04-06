// @Title: Missing Number
// @Author: colinjxc
// @Date: 2018-10-15T23:27:46+08:00
// @URL: https://leetcode-cn.com/problems/missing-number


int missingNumber(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++)
        result ^= nums[i]^(i+1);
    return result;
}
