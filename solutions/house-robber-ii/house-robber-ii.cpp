// @Title: House Robber II
// @Author: colinjxc
// @Date: 2022-01-06T15:55:59+08:00
// @URL: https://leetcode-cn.com/problems/house-robber-ii


class Solution {
public:
    //  在不偷窃第一个房子的情况下
    //  在不偷窃最后一个房子的情况下
    int rob(vector<int>& nums) {
        auto cnt = nums.size();
        if (cnt == 0) {
            return 0;
        } else if (cnt == 1) {
            return nums[0]; 
        }
        return max(robRange(nums, 0, cnt - 1), robRange(nums, 1, cnt));
    }

    int robRange(vector<int>& nums, int start, int end) {
        int curr = 0;
        int pre = 0;
        for (int i = start; i < end; i++) {
            auto tmp = max(curr, pre + nums[i]);
            pre = curr;
            curr = tmp;
        }
        return curr;
    }
};
