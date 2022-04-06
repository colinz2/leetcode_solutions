// @Title: House Robber
// @Author: colinjxc
// @Date: 2022-01-06T15:23:38+08:00
// @URL: https://leetcode-cn.com/problems/house-robber


class Solution {
public:
    int rob(vector<int>& nums) {
        int cnt = nums.size();
        vector<int> r(cnt, 0);

        if (cnt == 1) return nums[0];

        r[0] = nums[0];
        r[1] = max(nums[0], nums[1]);

        for (int i = 2; i < cnt; i++) {
            r[i] = max(r[i-1], r[i-2]+nums[i]);
        }

        return r[cnt - 1];
    }
};
