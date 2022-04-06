// @Title: 数组中重复的数字 LCOF
// @Author: colinjxc
// @Date: 2021-07-19T13:02:28+08:00
// @URL: https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof


class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        auto len = nums.size();
        for (auto i = 0; i < len; i++) {
            auto idx = nums[i] % len;
            if (nums[idx] >= len ) {
                return idx;
            }
            nums[idx] += len;
        }
        return -1;
    }
};
