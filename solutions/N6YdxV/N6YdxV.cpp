// @Title: 查找插入位置
// @Author: colinjxc
// @Date: 2022-02-07T15:20:08+08:00
// @URL: https://leetcode-cn.com/problems/N6YdxV


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int m = (lo + hi) >> 1;
            if (nums[m] < target) {
                lo = m + 1;
            } else if (nums[m] > target) {
                hi = m;
            } else {
                return m;
            }
        }
        return lo;
    }
};
