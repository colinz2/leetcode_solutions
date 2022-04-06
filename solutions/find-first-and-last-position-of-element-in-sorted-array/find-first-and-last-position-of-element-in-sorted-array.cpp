// @Title: Find First and Last Position of Element in Sorted Array
// @Author: colinjxc
// @Date: 2022-01-26T16:59:55+08:00
// @URL: https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lower_bound = [&]() ->int {
            int j = 0, k = nums.size();
            while (j < k) {
                int m = j + (k -j)/2;
                if (nums[m] < target) {
                    j = m + 1;
                } else {
                    k = m;
                }
            }
            return j;
        };

        auto upper_bound = [&]() -> int {
            int j = 0, k = nums.size();
            while (j < k) {
                int m = j + (k-j)/2;
                if (nums[m] <= target) {
                    j = m + 1;
                } else {
                    k = m;
                }
            }
            return j;
        };

        int j = lower_bound(), 
            k = upper_bound();
        if (j == k) {
            return {-1, -1};
        }

        return {j, k-1};
    }
};
