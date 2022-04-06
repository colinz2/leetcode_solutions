// @Title: Search in a Sorted Array of Unknown Size
// @Author: colinjxc
// @Date: 2022-01-26T02:29:07+08:00
// @URL: https://leetcode-cn.com/problems/search-in-a-sorted-array-of-unknown-size


/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int i = 0, j = 10e4;
        while (i < j) {
            int m = i + (j - i)/2;
            if (reader.get(m) == INT_MAX) {
                j = m;
            } else {
                i = m + 1;
            }
        }
        
        j = 0;

        while (j < i) {
            int m = j + (i - i)/2;
            if ((reader.get(m) < target)) {
                j = m + 1;
            } else if ((reader.get(m) > target)) {
                i = m;
            } else {
                return m;
            }
        }
        return -1;
    }
};
