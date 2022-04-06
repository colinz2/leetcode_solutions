// @Title: 数组中重复的数字 LCOF
// @Author: colinjxc
// @Date: 2021-07-19T13:17:45+08:00
// @URL: https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof


int findRepeatNumber(int* nums, int numsSize){
    for (int i = 0; i < numsSize; i++) {
        int idx = nums[i] % numsSize;
        if (nums[idx] >= numsSize) {
            return idx;
        }
        nums[idx] += numsSize;
    }
    return -1;
}
