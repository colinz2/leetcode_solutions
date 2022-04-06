// @Title: Jump Game
// @Author: colinjxc
// @Date: 2022-02-15T22:38:08+08:00
// @URL: https://leetcode-cn.com/problems/jump-game


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far_most = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (far_most < i) 
                return false;
            if (nums[i] + i > far_most) {
                far_most = nums[i] + i;
            }
            if (far_most >= nums.size() - 1)
                return true;
        }
        return far_most >= nums.size() - 1;
    }
};
