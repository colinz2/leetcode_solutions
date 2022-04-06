// @Title: Maximum Product of Three Numbers
// @Author: colinjxc
// @Date: 2018-12-06T20:45:37+08:00
// @URL: https://leetcode-cn.com/problems/maximum-product-of-three-numbers


class Solution {
public:
    int maximumProduct(vector<int>& nums) {        
        if (nums.size() < 3) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int a = nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];
        int b = nums[nums.size() - 1]* nums[0] * nums[1];
        return a > b ? a : b;
    }
};
