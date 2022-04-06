// @Title: Sort Array By Parity
// @Author: colinjxc
// @Date: 2022-02-05T18:22:41+08:00
// @URL: https://leetcode-cn.com/problems/sort-array-by-parity


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                swap(nums[i], nums[j++]);
            }
        }
        return nums;
    }
};
