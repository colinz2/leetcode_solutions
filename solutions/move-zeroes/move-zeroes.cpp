// @Title: Move Zeroes
// @Author: colinjxc
// @Date: 2022-01-27T13:10:15+08:00
// @URL: https://leetcode-cn.com/problems/move-zeroes


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {
                if (j != k) {
                    std::swap(nums[k], nums[j]);   
                }
                k++;
            }
        }
    }
};
