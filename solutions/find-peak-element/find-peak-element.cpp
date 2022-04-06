// @Title: Find Peak Element
// @Author: colinjxc
// @Date: 2022-03-05T23:30:06+08:00
// @URL: https://leetcode-cn.com/problems/find-peak-element


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            if (nums[mid] < nums[mid+1]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return hi;
    }
};
