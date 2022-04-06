// @Title: Find Pivot Index
// @Author: colinjxc
// @Date: 2022-02-14T19:00:00+08:00
// @URL: https://leetcode-cn.com/problems/find-pivot-index


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int lo = 0, l_sum = 0;
        while (lo < nums.size()) {
            if (l_sum == sum - nums[lo]) {
                return lo;
            } else {
                l_sum += nums[lo];
                sum -= nums[lo];
                lo++;
            }
        }
        return -1;
    }
};
