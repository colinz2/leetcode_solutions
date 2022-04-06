// @Title: Single Number
// @Author: colinjxc
// @Date: 2022-01-26T04:36:55+08:00
// @URL: https://leetcode-cn.com/problems/single-number


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int yh = 0;
        int i = 0;
        for (; i + 3 < nums.size(); i += 4) {
            yh ^= nums[i];
            yh ^= nums[i+1];
            yh ^= nums[i+2];
            yh ^= nums[i+3];
        }

        for (; i < nums.size(); i++) {
            yh ^= nums[i];
        }
        return yh;
    }
};
