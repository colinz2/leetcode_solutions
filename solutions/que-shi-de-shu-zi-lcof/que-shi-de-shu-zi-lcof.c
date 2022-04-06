// @Title: 缺失的数字  LCOF
// @Author: colinjxc
// @Date: 2022-02-07T12:33:12+08:00
// @URL: https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof


int missingNumber(int* nums, int numsSize){
    int i = 0; 
    for (; i < numsSize; i++) {
        if (nums[i] != i) {
            return i;
        }
    }
    return i;
}
