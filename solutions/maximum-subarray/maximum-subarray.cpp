// @Title: Maximum Subarray
// @Author: colinjxc
// @Date: 2022-02-12T18:50:06+08:00
// @URL: https://leetcode-cn.com/problems/maximum-subarray


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (sum < 0) {
                sum = nums[i];
            } else {
                sum += nums[i];
            }

            if (sum > max_sum) {
                max_sum = sum;
            }
        }
        return max_sum;
    }
};
