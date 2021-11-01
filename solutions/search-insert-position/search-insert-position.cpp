// @Title: Search Insert Position
// @Author: realzhangm
// @Date: 2021-10-30T21:59:19+08:00
// @URL: https://leetcode-cn.com/problems/search-insert-position


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int mid = 0;
        while (l <= r) {
            mid = l + (r - l)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
