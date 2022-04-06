// @Title: Binary Search
// @Author: colinjxc
// @Date: 2022-02-08T03:20:07+08:00
// @URL: https://leetcode-cn.com/problems/binary-search


int search(int* nums, int numsSize, int target){
    int i = 0, j = numsSize;
    while (i < j) {
        int m = (i+j)>>1;
        if (nums[m] < target) {
            i = m + 1;
        } else if (nums[m] > target) {
            j = m;
        } else {
            return m; 
        }
    }
    return -1;
}
