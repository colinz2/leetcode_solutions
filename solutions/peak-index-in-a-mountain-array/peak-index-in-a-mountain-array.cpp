// @Title: Peak Index in a Mountain Array
// @Author: colinjxc
// @Date: 2022-02-08T03:51:06+08:00
// @URL: https://leetcode-cn.com/problems/peak-index-in-a-mountain-array


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lo = 0, hi = arr.size();
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            if (arr[mid] < arr[mid+1]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return hi;
    }
};
