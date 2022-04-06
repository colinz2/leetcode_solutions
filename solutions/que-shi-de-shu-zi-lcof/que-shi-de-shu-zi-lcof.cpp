// @Title: 缺失的数字  LCOF
// @Author: colinjxc
// @Date: 2022-02-08T10:29:20+08:00
// @URL: https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mid = (lo + hi) /2;
            if (nums[mid] == mid) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return hi;
    }
};
