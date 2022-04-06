// @Title: 连续子数组的最大和  LCOF
// @Author: colinjxc
// @Date: 2022-02-15T20:30:45+08:00
// @URL: https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0], sum = 0;
        for (auto num : nums) {
            if (sum < 0) {
                sum = num;
            } else {
                sum += num;
            }
            max_sum = std::max(max_sum, sum);
        }
        return max_sum;
    }
};
