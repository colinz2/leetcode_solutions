// @Title: Minimum Size Subarray Sum
// @Author: colinjxc
// @Date: 2018-11-28T23:40:25+08:00
// @URL: https://leetcode-cn.com/problems/minimum-size-subarray-sum


class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int l = 0, r = -1;
        int sum = 0;
        int ret = nums.size() + 1;

        while (l < nums.size()) {
            if (r + 1 < nums.size() && sum < s) {
                sum += nums[++r];
            } else {
                sum -= nums[l++];
            }

            if (sum >= s) {
                ret = std::min(ret, r-l+1);
            }
        }
        if (ret > nums.size()) ret = 0;
        return ret;
    }
};

