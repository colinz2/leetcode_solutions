// @Title: Missing Number
// @Author: colinjxc
// @Date: 2018-10-15T23:20:13+08:00
// @URL: https://leetcode-cn.com/problems/missing-number


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        auto sum = std::accumulate(nums.begin(), nums.end(), 0);
        auto size = nums.size();
        return  (size * (size + 1) /2) - sum;
    }
};
