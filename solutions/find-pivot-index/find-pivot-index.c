// @Title: Find Pivot Index
// @Author: colinjxc
// @Date: 2022-02-14T19:05:11+08:00
// @URL: https://leetcode-cn.com/problems/find-pivot-index


// sum + nums[i] + sum = total
// 2sum = total = num[i]
int pivotIndex(int* nums, int numsSize){
    int total = 0, sum = 0;
    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        if (sum + sum + nums[i] == total) {
            return i;
        }
        sum += nums[i];
    }

    return -1;
}
