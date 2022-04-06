// @Title: Single Element in a Sorted Array
// @Author: colinjxc
// @Date: 2022-02-14T01:49:25+08:00
// @URL: https://leetcode-cn.com/problems/single-element-in-a-sorted-array


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            if (mid % 2) mid--;
            if (nums[mid] == nums[mid + 1]) {
                lo += 2;
            } else {
                hi = mid;
            }
        }
        return nums[hi];
    }
};
