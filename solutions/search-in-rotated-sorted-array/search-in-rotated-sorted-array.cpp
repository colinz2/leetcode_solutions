// @Title: Search in Rotated Sorted Array
// @Author: colinjxc
// @Date: 2022-02-09T17:36:40+08:00
// @URL: https://leetcode-cn.com/problems/search-in-rotated-sorted-array


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] < nums[hi]) {
                if (nums[mid] < target && target <= nums[hi]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            } else {
                if (nums[lo] <= target && target < nums[mid]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }

        }
        return -1;
    }
};
