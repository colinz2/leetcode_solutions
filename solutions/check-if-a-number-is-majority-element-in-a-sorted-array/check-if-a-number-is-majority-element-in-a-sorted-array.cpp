// @Title: Check If a Number Is Majority Element in a Sorted Array
// @Author: colinjxc
// @Date: 2022-02-07T11:39:44+08:00
// @URL: https://leetcode-cn.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array


class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int cnt = 0;
        for (auto n : nums) {
            if (target == n) cnt++;
            else if (target < n) break;
        }
        return cnt > nums.size()/2;
    }
};
