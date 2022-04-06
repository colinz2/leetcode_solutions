// @Title: Check If a Number Is Majority Element in a Sorted Array
// @Author: colinjxc
// @Date: 2022-02-07T11:57:28+08:00
// @URL: https://leetcode-cn.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array


bool isMajorityElement(int* nums, int numsSize, int target){
    int start = 0, end = numsSize-1;
    int targetSize = 0;
    while (start < end) {
        if (nums[start] != target) {
            start++;
        } else if (nums[end] != target) {
            end--;
        }
        if (targetSize == end-start+1) {
            return targetSize > numsSize/2;
        } else {
            targetSize = end-start+1;
        }
    }
    return false;
}
