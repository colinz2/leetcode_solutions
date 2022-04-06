// @Title: Search in a Sorted Array of Unknown Size
// @Author: colinjxc
// @Date: 2022-02-02T20:56:31+08:00
// @URL: https://leetcode-cn.com/problems/search-in-a-sorted-array-of-unknown-size


/**
 * *********************************************************************
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * int getElement(ArrayReader *, int index);
 */

int search(struct ArrayReader* reader, int target) {
    int i = 0, j = 10e4+1;

    while (i < j) {
        int m = (i+j)>>1;
        int res = getElement(reader, m);
        if (res > target) {
            j = m;
        } else if (res < target) {
            i = m + 1;
        } else {
            return m;
        }
    }

    return -1;    
}
