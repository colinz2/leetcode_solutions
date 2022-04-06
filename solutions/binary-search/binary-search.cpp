// @Title: Binary Search
// @Author: colinjxc
// @Date: 2022-01-10T18:44:34+08:00
// @URL: https://leetcode-cn.com/problems/binary-search


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l)/2;
            if (target > nums[mid]) {
                l = mid + 1;
            } else if (target < nums[mid]) {
                r = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
